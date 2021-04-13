#include "rtda/Frame.h"

Frame::Frame(u2 maxLocals, u2 maxStack, u4 code_length, char *codes)
{
    localVars = new LocalVars(maxLocals);
    operandStack = new OperandStack(maxStack);
    this->code_length = code_length;
    this->codes = codes;
    lower = NULL;
}

u1 Frame::get_code(u4 pc)
{
    if (pc >= code_length)
        exit_with_massage("pc out of code length");
    return (u1)codes[pc];
}

u1 Frame::get_u1(u4 pc)
{
    return (u1)codes[pc + 1];
}

u2 Frame::get_u2(u4 pc)
{
    union
    {
        u1 _u1[2];
        u2 _u2;
    } a;
    a._u1[0] = codes[pc + 1];
    a._u1[1] = codes[pc + 2];
    return a._u2;
}

u4 Frame::get_u4(u4 pc)
{
    union
    {
        u1 _u1[4];
        u4 _u4;
    } a;
    a._u1[0] = codes[pc + 1];
    a._u1[1] = codes[pc + 2];
    a._u1[2] = codes[pc + 3];
    a._u1[3] = codes[pc + 4];

    return a._u4;
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

void Frame::push_jint(jint a)
{
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

void Frame::push_jboolean(jboolean a)
{
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
void Frame::push_jdouble(jdouble a)
{
    byte_64 byte64;
    byte64._jdouble = a;
    //下面2句的顺序决定了内部数据的存储是大端还是小端
    //要与pop的顺序保持一致
    operandStack->push(byte64._u4[0]);
    operandStack->push(byte64._u4[1]);
}

jint Frame::pop_jint()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jint;
}
jbyte Frame::pop_jbyte()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jbyte;
}
jboolean Frame::pop_jboolean()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jboolean;
}
jchar Frame::pop_jchar()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jchar;
}
jshort Frame::pop_jshort()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jshort;
}
jlong Frame::pop_jlong()
{
    byte_64 byte64;
    byte64._u4[1] = operandStack->getTop();
    operandStack->pop();
    byte64._u4[0] = operandStack->getTop();
    operandStack->pop();
    return byte64._jlong;
}
jfloat Frame::pop_jfloat()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jfloat;
}
jdouble Frame::pop_jdouble()
{
    byte_64 byte64;
    byte64._u4[1] = operandStack->getTop();
    operandStack->pop();
    byte64._u4[0] = operandStack->getTop();
    operandStack->pop();
    return byte64._jdouble;
}

jint Frame::load_jint(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jint;
}
jbyte Frame::load_jbyte(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jbyte;
}
jboolean Frame::load_jboolean(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jboolean;
}
jchar Frame::load_jchar(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jchar;
}
jshort Frame::load_jshort(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jshort;
}
jfloat Frame::load_jfloat(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jfloat;
}

jlong Frame::load_jlong(u2 shift)
{
    byte_64 byte64;
    byte64._u4[0] = localVars->load(shift);
    byte64._u4[1] = localVars->load(shift + 1);
    return byte64._jlong;
}

jdouble Frame::load_jdouble(u2 shift)
{
    byte_64 byte64;
    byte64._u4[0] = localVars->load(shift);
    byte64._u4[1] = localVars->load(shift + 1);
    return byte64._jdouble;
}

jint Frame::store_jint(u2 shift, jint a)
{
    byte_32 byte32;
    byte32._jint = a;
    localVars->store(shift, byte32._u4);
}
jbyte Frame::store_jbyte(u2 shift, jbyte a)
{
    byte_32 byte32;
    byte32._jbyte = a;
    localVars->store(shift, byte32._u4);
}
jboolean Frame::store_jboolean(u2 shift, jboolean a)
{
    byte_32 byte32;
    byte32._jboolean = a;
    localVars->store(shift, byte32._u4);
}
jchar Frame::store_jchar(u2 shift, jchar a)
{
    byte_32 byte32;
    byte32._jchar = a;
    localVars->store(shift, byte32._u4);
}
jshort Frame::store_jshort(u2 shift, jshort a)
{
    byte_32 byte32;
    byte32._jshort = a;
    localVars->store(shift, byte32._u4);
}
jfloat Frame::store_jfloat(u2 shift, jfloat a)
{
    byte_32 byte32;
    byte32._jfloat = a;
    localVars->store(shift, byte32._u4);
}
jlong Frame::store_jlong(u2 shift, jlong a)
{
    byte_64 byte64;
    byte64._jlong = a;
    localVars->store(shift, byte64._u4[0]);
    localVars->store(shift + 1, byte64._u4[1]);
}
jdouble Frame::store_jdouble(u2 shift, jdouble a)
{
    byte_64 byte64;
    byte64._jdouble = a;
    localVars->store(shift, byte64._u4[0]);
    localVars->store(shift + 1, byte64._u4[1]);
}