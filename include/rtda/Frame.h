#pragma once
#include"LocalVars.h"
#include"OperandStack.h"
#include"rtda_tpdef.h"

class Frame
{
private:
    Frame *lower;
    LocalVars *localVars;
    OperandStack *operandStack;

public:
    Frame(u4 maxLocals,u4 maxStack);
    ~Frame();
};