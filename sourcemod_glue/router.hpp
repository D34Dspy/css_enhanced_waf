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

// CDelegate has to be a fastdelegate type!
template <typename CDelegate, typename CInterface>
class SourcemodRouter {

public:
    typedef typename CDelegate::DesiredRetType RetType;
    typedef SourcemodRoutedValue<RetType> RetStore;
    typedef SourcemodInvocationRecord<RetStore> Invoke;
    typedef struct CDelegate::ParameterSet ParamSet;
private:
    
    struct Endpoint {
        int keyCode;
        CInterface* keyIface;
        CDelegate delegate;
    };

    int keyCodes;
    CUtlVector<Endpoint> begin;
    CUtlVector<Endpoint> end;

    CInterface* curr;
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
        for (int j = 0; j < begin.Count(); j++)
        {
            auto& route = begin.Element(j);
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
        for (int j = 0; j < end.Count(); j++)
        {
            if(!end.IsValidIndex(j))
                continue;
            auto& route = end.Element(j);
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
        rec.recordIsCurrent = true;
        return rec.returnValue;
    }
    int add(CDelegate delegate, CInterface* iface, int overload = 0) {
        auto& store = (overload ? end : begin);
        int code = keyCodes++;
        store.AddToTail(Endpoint {
                code,
                iface,
                delegate
            }
        );
        return code;
    }
    void remove(int hook, CInterface* iface, int overload = 0) {
        for(int i = 0; i < begin.Count(); i++) {
            auto& e = begin.Element(i);
            if(e.keyCode == hook)
            {
                begin.Remove(i);
                return;
            }
        }
        for(int i = 0; i < end.Count(); i++) {
            auto& e = end.Element(i);
            if(e.keyCode == hook)
            {
                end.Remove(i);
                return;
            }
        }
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

    bool overwrite_return() const { return currentRecord.overwriteReturn; }
    bool skip_original() const { return currentRecord.skipOriginal; }
    bool plugin_took_action() const { return currentRecord.pluginTookAction; }

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