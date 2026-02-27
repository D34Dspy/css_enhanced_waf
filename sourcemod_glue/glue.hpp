#pragma once

#ifndef GLUE_HPP
#define GLUE_HPP

typedef unsigned CallbackHandle;

template <typename FuncSig>
class CallbackManager {
    public:
    CallbackHandle Add();
    void Rem(CallbackHandle);
    void On(CallbackHandle);
    void Off(CallbackHandle);
    void Toggle(CallbackHandle);
    bool IsOn(CallbackHandle);
};


#endif // !GLUE_HPP