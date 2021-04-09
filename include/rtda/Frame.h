#pragma once
#include"classfile/classfile.h"
#include"LocalVars.h"
#include"OperandStack.h"


class Frame
{
private:
    LocalVars *localVars;
    OperandStack *operandStack;
    u4 code_length;
    char* codes;

public:
    Frame *lower;//链表
    Frame(u4 maxLocals,u4 maxStack,u4 code_length,char* codes);
    char getCode(u4 pc);
    ~Frame();
};