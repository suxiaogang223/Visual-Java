#pragma once
#include"jvm_typedef.h"
#include"error_exit.h"

class OperandStack
{
private:
    u2 maxStack;
    u4 *stack;
    u2 index; //当前指针
public:
    OperandStack(u2 maxStack);
    void printOperandStack();
    void push(u4 operand);
    void pop();
    u4 getTop();
    ~OperandStack();
};