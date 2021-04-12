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
    Frame(u2 maxLocals,u2 maxStack,u4 code_length,char* codes);
    u1 get_code(u4 pc);
    u1 get_u1(u4 pc);
    u2 get_u2(u4 pc);
    u4 get_u4(u4 pc);

    //对操作数栈的一系列操作
    void push_jint(jint a);
    void push_jbyte(jbyte a);
    void push_jboolean(jboolean a);
    void push_jchar(jchar a);
    void push_jshort(jshort a);
    void push_jlong(jlong a);
    void push_jfloat(jfloat a);
    void push_jdouble(jdouble a);

    //对本地变量表的一些操作
    jint load_jint(u2 shift);
    jbyte load_jbyte(u2 shift);
    jboolean load_jboolean(u2 shift);
    jchar load_jchar(u2 shift);
    jshort load_jshort(u2 shift);
    jfloat load_jfloat(u2 shift);
    jlong load_jlong(u2 shift);
    jdouble load_jdouble(u2 shift);

    ~Frame();
};