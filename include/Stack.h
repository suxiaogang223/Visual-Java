#pragma once
#include "Frame.h"
class Stack
{
private:
    u4 maxSize;
    u4 size;
    Frame *_top;
public:
    Stack(u4 maxSize);
    void push(Frame *frame);
    void pop();
    Frame* top();
    ~Stack();
};