#pragma once
#include "Stack.h"
#include"rtda_typedef.h"
class Thread
{
private:
    int pc;
    Stack *stack;

public:
    Thread(u4 maxSize);
    void setPC(int pc);
    int getPC();
    void pushFrame(Frame *frame);
    void popFrame();
    Frame* currentFrame();
    ~Thread();
};