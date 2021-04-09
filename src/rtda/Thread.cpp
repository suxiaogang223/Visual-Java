#include"rtda/Thread.h"
#include"error_exit.h"

Thread::Thread(u4 maxSize){
    stack = new Stack(maxSize); 
}

u4 Thread::getPC(){
    return pc;
}

void Thread::setPC(u4 pc){
    this->pc = pc;
}

Frame* Thread::currentFrame(){
    return stack->top();
}

void Thread::pushFrame(Frame *frame){
    stack->push(frame);
}

void Thread::popFrame(){
    stack->pop();
}


Thread::~Thread(){
    free(stack);
}

