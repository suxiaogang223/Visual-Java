#include "rtda/Frame.h"

Frame::Frame(u4 maxLocals, u4 maxStack, u4 code_length, char *codes)
{
    localVars = new LocalVars(maxLocals);
    operandStack = new OperandStack(maxStack);
    this->code_length = code_length;
    this->codes = codes;
    lower = NULL;
}

u1 Frame::getCode(u4 pc)
{
    if (pc >= code_length)
        exit_with_massage("pc out of code length");
    return codes[pc];
}

jbyte Frame::getByte(u4 pc){
    return codes[pc+1];
}
jshort Frame::getShort(u4 pc){
    return ((jshort)codes[pc+1])<<8+(jshort)codes[pc+2];//需验证
}

Frame::~Frame()
{
    free(localVars);
    free(operandStack);
}


void Frame::push_jbyte(jbyte a)
{
    byte_32 byte32;
    byte32._jbyte = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}

void Frame::push_jint(jint a){
    byte_32 byte32;
    byte32._jint = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}
void Frame::push_jchar(jchar a)
{
    byte_32 byte32;
    byte32._jchar = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}

void Frame::push_jboolean(jboolean a){
    byte_32 byte32;
    byte32._jboolean = a;
    operandStack->push(byte32._u4);
}

void Frame::push_jshort(jshort a)
{
    byte_32 byte32;
    byte32._jshort = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}
void Frame::push_jlong(jlong a)
{
    byte_64 byte64;
    byte64._jlong = a;
    //下面2句的顺序决定了内部数据的存储是大端还是小端
    //要与pop的顺序保持一致
    operandStack->push(byte64._u4[0]);
    operandStack->push(byte64._u4[1]);
}
void Frame::push_jfloat(jfloat a)
{
    byte_32 byte32;
    byte32._jfloat = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}
void Frame::push_jdouble(jdouble a){
    byte_64 byte64;
    byte64._jdouble = a;
    operandStack->push(byte64._u4[0]);
    operandStack->push(byte64._u4[1]);
}
