#pragma once

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "utlvector.h"

template <typename T>
struct SourcemodRoutedValue {
    T value;
    T& unwrap() {
        return value;
    }
    const T& unwrap() const {
        return value;
    }
};

template<>
struct SourcemodRoutedValue<void> {
    void unwrap() const { }
};

template <typename T>
struct SourcemodInvocationRecord {
    bool pluginTookAction;
    bool parametersAltered;
    bool skipOriginal;
    bool overwriteReturn;
    bool stopDelegation;
    bool recordIsCurrent;
    T returnValue;
    SourcemodInvocationRecord() 
        : pluginTookAction(false)
        , skipOriginal(false)
        , overwriteReturn(false)
        , stopDelegation(false)
        , recordIsCurrent(false)
        , returnValue({})
    {
    }
    SourcemodInvocationRecord(const SourcemodInvocationRecord<T>& rec) 
        : pluginTookAction(rec.pluginTookAction)
        , skipOriginal(rec.skipOriginal)
        , overwriteReturn(rec.overwriteReturn)
        , stopDelegation(rec.stopDelegation)
        , recordIsCurrent(rec.recordIsCurrent)
        , returnValue(rec.returnValue)
    {
    }
};

constexpr size_t INVOCATION_DEPTH = 32;

template <typename T>
struct SourcemodInvokeStack {
    typedef SourcemodInvocationRecord<T> Record;
    Record context[INVOCATION_DEPTH];
    size_t cursor;

    SourcemodInvokeStack() {
        cursor = 0;
    }

    bool empty() {
        return cursor == 0;
    }

    Record& enter_context() {
        context[cursor] = cursor ? context[cursor - 1] : Record();
        return context[cursor++];
    }

    void leave_context() {
        if (cursor == 0)
            *(int*)0 = 0;
        context[cursor - 1] = context[cursor];
        cursor--;
    }

    Record& tail() { return context[cursor - 1]; }
    const Record& tail() const { return context[cursor - 1]; }

};

template <typename T>
struct SourcemodInvokeStackOwnership {
    typedef SourcemodInvokeStack<T> Stack;
    typedef typename Stack::Record Record;
    Stack& stack;
    Record& record;
    SourcemodInvokeStackOwnership(Stack& s) : stack(s), record(s.enter_context()) {}
    ~SourcemodInvokeStackOwnership() {
        stack.leave_context();
    }
};

// CDelegate has to be a fastdelegate type!
template <typename CDelegate, typename CInterface>
class SourcemodRouter {

public:
    typedef typename CDelegate::DesiredRetType RetType;
    typedef SourcemodRoutedValue<RetType> RetStore;
    typedef SourcemodInvocationRecord<RetStore> Invoke;
    typedef struct CDelegate::ParameterSet ParamSet;
    typedef SourcemodInvokeStack<RetStore> Stack;
private:
    
    struct Endpoint {
        int keyCode;
        CInterface* keyIface;
        CDelegate delegate;
    };

    struct Routes {
        int overload;
        CUtlVector<Endpoint> routes;

        int add(int keyCode, CDelegate d, CInterface* i) {
            int j = routes.AddToTail();
            routes.Element(j).keyCode = keyCode;
            routes.Element(j).keyIface = i;
            routes.Element(j).delegate = d;
            return j;
        }

        void rem(int hk, CInterface* iface) {
            for(int i = 0; i < routes.Count(); i++) {
                if(routes.Element(i).keyCode == hk && routes.Element(i).keyIface == iface)
                {
                    routes.Remove(i);
                    return;
                }
            }
        }

        int invalid() {
            return -1;
        }
    };
    
    int keyCodes;
    CUtlVector<Routes> routers; // lord forgive me

    CInterface* curr;
    Stack stack;
    ParamSet param;
    bool paramAltered;

    RetStore orig;
    bool origSet;
    RetStore alter;
    bool alterSet;

    int mres;

    Invoke currentRecord;

    void throw_() {
        *(int*)0 = 0;
    }

    int establish_routes(int overload) {
        int i = routers.AddToTail();
        routers.Element(i).overload = overload;
        return i;
    }

    int overload(int value, bool create = true) {
        for (int i = 0; i < routers.Count(); i++)
            if(routers.Element(i).overload == value)
                return i;
        if (create) {
            int j = routers.AddToTail();
            routers.Element(j).overload = value;
            return j;
        }
        return invalid();
    }

    void sorted() {
        for(int i = 0; i < routers.Count() - 1; i++) {
            int minIdx = i;
            for(int j = i + 1; j < routers.Count(); j++) {
                if(routers.Element(j).overload < routers.Element(minIdx).overload) {
                    minIdx = j;
                }
            }
            if(minIdx != i) {
                Routes& l = routers.Element(i);
                Routes& r = routers.Element(minIdx);
                
                int tempOverload = l.overload;
                l.overload = r.overload;
                r.overload = tempOverload;
                
                l.routes.Swap(r.routes);
            }
        }

    }

    Stack& before_ownership_update_param() {
        paramAltered = !stack.empty();
        return stack;
    }

public:
    SourcemodRouter() {
        keyCodes = INT_MIN;
    }
    template <typename... T>
    RetStore invoke_pre(CInterface* iface, T... params) {
        auto& rec = this->currentRecord;

        this->curr = iface;
        this->alterSet = false;
        this->origSet = false;
        this->paramAltered = false;
        rec.recordIsCurrent = false;
        rec.overwriteReturn = false;
        rec.parametersAltered = false;
        rec.stopDelegation = false;
        rec.skipOriginal = false;

        // param = ParamSet(params...);
        auto cpy = ParamSet(params...);
        memcpy(&param,&cpy, sizeof(ParamSet));

        rec.stopDelegation = false;
        rec.parametersAltered = false;
        for(int i = 0; i < routers.Count(); i++) {
            auto& router = routers.Element(i);
            if (router.overload != 0)
                continue;
            for (int j = 0; j < router.routes.Count(); j++)
            {
                auto& route = router.routes.Element(j);
                if(route.keyIface != iface && route.keyIface != nullptr)
                    continue;
                route.delegate(params...);
                alter = rec.returnValue;
                alterSet = true;
                memcpy(&currentRecord, &rec, sizeof(Invoke));
                if(rec.stopDelegation)
                    break;
                if(paramAltered)
                    param.unwrap(params...);
            }
            if(rec.stopDelegation)
                break;
        }
        rec.recordIsCurrent = true;
        return rec.returnValue;
    }
    template <typename... T>
    RetStore invoke_post(CInterface* iface, RetStore previous, T... params) {
        curr = iface;
        auto& rec = currentRecord;
        rec.returnValue = previous;

        // param = ParamSet(params...);
        auto cpy = ParamSet(params...);
        memcpy(&param,&cpy, sizeof(ParamSet));

        rec.stopDelegation = false;
        rec.parametersAltered = false;
        for(int i = 0; i < routers.Count(); i++) {
            auto& router = routers.Element(i);
            if (router.overload != 1)
                continue;
            for (int j = 0; j < router.routes.Count(); j++)
            {
                auto& route = router.routes.Element(j);
                if(route.keyIface != iface && route.keyIface != nullptr)
                    continue;
                route.delegate(params...);
                alter = rec.returnValue;
                alterSet = true;
                if(rec.stopDelegation)
                    break;
                if(paramAltered)
                    param.unwrap(params...);
            }
            if(rec.stopDelegation)
                break;
        }
        rec.recordIsCurrent = true;
        return rec.returnValue;
    }
    int add(CDelegate delegate, CInterface* iface, int overload = 0) {
        auto m = this->overload(overload);
        int i = routers.Element(m).add(keyCodes++, delegate, iface);
        sorted();
        return i;
    }
    void remove(int hook, CInterface* iface, int overload = 0) {
        auto m = this->overload(overload, false);
        if(m == invalid())
        {
            m = establish_routes(overload);
            return;
        }
        routers[m].rem(hook, iface);
    }

    int invalid() {
        return -1;
    }

    void create_return(int status) {
        create_return(status, RetStore());
    }
    void create_return(int status, RetStore val) {
        mres = status;
        switch(status) {
            default:
                *(int*)0 = 0;
            case 0: // MRES_IGNORED=0, // plugin didn't take any action
                return create_return(false, false, false, val);
            case 1: // MRES_HANDLED, // plugin did something, but real function should still be called
                return create_return(true, false, false, val);
            case 2: // MRES_OVERRIDE, // call real function, but use my return value
                return create_return(true, false, true, val);
            case 3: // MRES_SUPERCEDE // skip real function; use my return value
                return create_return(true, true, true, val);
        }
    }

    int metamod_result() const {
        return mres;
    }

    void create_return(bool plugin_took_action, bool skip_original, bool overwrite_return, RetStore val) {
        currentRecord.pluginTookAction = plugin_took_action;
        currentRecord.skipOriginal = skip_original;
        currentRecord.overwriteReturn = overwrite_return;
        currentRecord.stopDelegation = overwrite_return;
        currentRecord.recordIsCurrent = true;
        currentRecord.returnValue = RetStore{val};
    }

    bool overwrite_return() const { return stack.tail().overwriteReturn; }
    bool skip_original() const { return stack.tail().skipOriginal; }
    bool plugin_took_action() const { return stack.tail().pluginTookAction; }

    ParamSet& parameters() { return param; }

    RetStore& original_return_value() { if(!origSet)*(int*)0 = 0; return orig; }
    bool original_return_value_set() { return origSet; }
    void set_original_return_value(RetStore val) {
        origSet = true;
        orig = val;
    }

    RetStore& altered_return_value() { if(!alterSet)*(int*)0 = 0; return alter; }
    bool altered_return_value_set() { return alterSet; }

    bool parameters_altered() { return paramAltered; }
    void alter_parameters() { paramAltered = true; }
    CInterface* candidate() { return curr; }
};
#endif // !ROUTER_HPP