#pragma once

#include "vphysics_interface.h"
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
    int position_router;
    int position_route;
    SourcemodInvocationRecord() 
        : pluginTookAction(false)
        , skipOriginal(false)
        , overwriteReturn(false)
        , stopDelegation(false)
        , recordIsCurrent(false)
        , returnValue({})
        , position_router(0)
        , position_route(0)
    {
    }
    SourcemodInvocationRecord(const SourcemodInvocationRecord<T>& rec) 
        : pluginTookAction(rec.pluginTookAction)
        , skipOriginal(rec.skipOriginal)
        , overwriteReturn(rec.overwriteReturn)
        , stopDelegation(rec.stopDelegation)
        , recordIsCurrent(rec.recordIsCurrent)
        , returnValue(rec.returnValue)
        , position_router(rec.position_router)
        , position_route(rec.position_route)
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
        for(int i = 0; i < routers.Count(); i++) {
            int k = -1;
            for(int j = 0; j < routers.Count(); j++) {
                if(routers.Element(j).overload < routers.Element(i).overload)
                    k = j;
            }

            if(k == -1)
                break;

            Routes& l = routers.Element(i);
            Routes& r = routers.Element(k);
            int overload = l.overload;
            l.overload = r.overload;
            r.overload = overload;
            l.routes.Swap(r.routes);
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
    RetStore invoke(CInterface* iface, T... params) {
        curr = iface;
        auto ctx = SourcemodInvokeStackOwnership<RetStore>(before_ownership_update_param());
        auto& rec = ctx.record;

        // param = ParamSet(params...);
        auto cpy = ParamSet(params...);
        memcpy(&param,&cpy, sizeof(ParamSet));

        rec.stopDelegation = false;
        for(int i = rec.position_router; i < routers.Count(); i++) {
            auto& router = routers.Element(i);
            for (int j = rec.position_route; j < router.routes.Count(); j++)
            {
                auto& route = router.routes.Element(j);
                if(route.keyIface != iface || route.keyIface != nullptr)
                    continue;
                route.delegate(params...);
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

    bool loop(int& router, int& route, CDelegate* delegate) {

        if (router == routers.Count())
            return false;

        Routes& router_ = routers[router];

        if(route == router_.routes.Count())
        {
            if(router + 1 == routers.Count())
            {
                return false;
            }
            else
            {
                *delegate = router_.routes.Element(route).delegate;
                router += 1;
                route = 0;
            }
        }
        else {
            *delegate = router_.routes.Element(route).delegate;
            route += 1;
        }
        
        return true;
    }

    int invalid() {
        return -1;
    }

    void create_return(int status) {
        create_return(status, RetStore());
    }
    void create_return(int status, RetStore val) {
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

    void create_return(bool plugin_took_action, bool skip_original, bool overwrite_return, RetStore val) {
        stack.tail().pluginTookAction = plugin_took_action;
        stack.tail().skipOriginal = skip_original;
        stack.tail().overwriteReturn = overwrite_return;
        stack.tail().stopDelegation = overwrite_return;
        stack.tail().recordIsCurrent = true;
        stack.tail().returnValue = RetStore{val};
    }

    bool overwrite_return() const { return stack.tail().overwriteReturn; }
    bool skip_original() const { return stack.tail().skipOriginal; }
    bool plugin_took_action() const { return stack.tail().pluginTookAction; }

    ParamSet& parameters() { return param; }
    bool parameters_altered() { return paramAltered; }
    CInterface* candidate() { return curr; }
};
#endif // !ROUTER_HPP