#pragma once

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "utlvector.h"
        
template <typename CDelegate, typename CInterface>
class SourcemodRouter {
    
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

public:
    SourcemodRouter() {
        keyCodes = INT_MIN;
    }
    void invoke(CInterface* iface) {
        for(int i = 0; i < routers.Count(); i++) {
            auto& router = routers.Element(i);
            for (int j = 0; j < router.routes.Count(); j++)
            {
                auto& route = routers.routes.Element(j);
                route.delegate(iface);
            }
        }
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
};
#endif // !ROUTER_HPP