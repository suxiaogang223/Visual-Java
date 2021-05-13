#pragma once
#include "Stack.h"
#include<stack>


class Thread
{
private:
    u4 pc;
    Stack *stack;

public:
    Thread(u4 maxSize);
    void setPC(u4 pc);
    u4 getPC();
    void pushFrame(Frame *frame);
    void popFrame();
    Frame* currentFrame();
    void printThread();
    ~Thread();
};