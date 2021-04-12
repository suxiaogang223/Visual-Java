#pragma once
#include"classfile/classfile.h"
#include"LocalVars.h"
#include"OperandStack.h"
#include"jvm_typedef.h"


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
    u1 getCode(u4 pc);
    jbyte getByte(u4 pc);
    jshort getShort(u4 pc);

    //对操作数栈的一系列操作
    void push_jint(jint a);
    void push_jbyte(jbyte a);
    void push_jboolean(jboolean a);
    void push_jchar(jchar a);
    void push_jshort(jshort a);
    void push_jlong(jlong a);
    void push_jfloat(jfloat a);
    void push_jdouble(jdouble a);

    ~Frame();
};