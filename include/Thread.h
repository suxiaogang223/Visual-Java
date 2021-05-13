#pragma once
// #include "Stack.h"
#include<stack>
#include "Frame.h"


class Thread
{
private:
    u4 pc;
    std::stack<Frame*> *vmStack;

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