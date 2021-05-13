#pragma once
#include "classfile.h"
#include "LocalVars.h"
#include "OperandStack.h"
#include "jvm_typedef.h"

class Frame
{
private:
    LocalVars *localVars;
    OperandStack *operandStack;
    u4 code_length;
    char *codes;
    ClassFile *classfile;

    //这些成员在打印时很有帮助
    std::string method_name;
    std::string method_descriptor;
    std::string class_name;

public:
    Frame *lower; //链表
    Frame(ClassFile *classfile, std::string class_name, std::string method_name, std::string method_descriptor);
    ClassFile *getClassFile();
    void printFrame();

    u1 get_code(u4 pc);
    u1 get_u1(u4 pc);
    u2 get_u2(u4 pc);
    u4 get_u4(u4 pc);

    //对操作数栈的一系列操作
    void push_byte32(byte_32 a);
    void push_byte64(byte_64 a);
    void push_jint(jint a);
    void push_jbyte(jbyte a);
    void push_jboolean(jboolean a);
    void push_jchar(jchar a);
    void push_jshort(jshort a);
    void push_jlong(jlong a);
    void push_jfloat(jfloat a);
    void push_jdouble(jdouble a);
    void push_jobject(jobject a);

    void pop();
    void pop2();
    void dup(); //复制栈顶数值并将两个复制值压入栈顶（不能是long和double）
    void dup_x1();
    void dup_x2();
    void dup2(); //复制栈顶数值（long,doubel)并将两个复制值压入栈顶
    void dup2_x1();
    void dup2_x2();
    void swap();

    jint pop_jint();
    jbyte pop_jbyte();
    jboolean pop_jboolean();
    jchar pop_jchar();
    jshort pop_jshort();
    jlong pop_jlong();
    jfloat pop_jfloat();
    jdouble pop_jdouble();
    jobject pop_jobject();

    //对本地变量表的一些操作
    jint load_jint(u2 shift);
    jbyte load_jbyte(u2 shift);
    jboolean load_jboolean(u2 shift);
    jchar load_jchar(u2 shift);
    jshort load_jshort(u2 shift);
    jfloat load_jfloat(u2 shift);
    jlong load_jlong(u2 shift);
    jdouble load_jdouble(u2 shift);
    jobject load_jobject(u2 shift);

    void store_jint(u2 shift, jint a);
    void store_jbyte(u2 shift, jbyte a);
    void store_jboolean(u2 shift, jboolean a);
    void store_jchar(u2 shift, jchar a);
    void store_jshort(u2 shift, jshort a);
    void store_jfloat(u2 shift, jfloat a);
    void store_jlong(u2 shift, jlong a);
    void store_jdouble(u2 shift, jdouble a);
    void store_jobject(u2 shift, jobject a);

    ~Frame();
};