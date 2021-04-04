#pragma once
#include"LocalVars.h"
#include"OperandStack.h"
#include"rtda_typedef.h"


class Frame
{
private:
    LocalVars *localVars;
    OperandStack *operandStack;

public:
    Frame *lower;//链表
    Frame(u4 maxLocals,u4 maxStack);
    ~Frame();
};