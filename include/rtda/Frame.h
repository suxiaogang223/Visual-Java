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
    
    //对操作数栈的一系列操作
    void ipush(int a);
    void bpush(char a);
    void lpush(long a);
    void fpush(float a);
    void dpush(double a);

    ~Frame();
};