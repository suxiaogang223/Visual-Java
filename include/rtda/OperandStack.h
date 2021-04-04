#pragma once
#include "rtda_tpdef.h"

class OperandStack
{
private:
    u4 maxStack;
    u4 *stack;
    u4 index; //当前指针
public:
    OperandStack(u4 maxStack);
    void push(u4 operand);
    void pop();
    u4 getTop();
    ~OperandStack();
};