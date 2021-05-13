#include "Thread.h"
#include "error_exit.h"

Thread::Thread(u4 maxSize)
{
    vmStack = new std::stack<Frame*>();
    pc = 0;
}

u4 Thread::getPC()
{
    return pc;
}

void Thread::setPC(u4 pc)
{
    this->pc = pc;
}

Frame *Thread::currentFrame()
{
    return vmStack->top();
}

void Thread::pushFrame(Frame *frame)
{
    vmStack->push(frame);
}

void Thread::popFrame()
{
    vmStack->pop();
}

void Thread::printThread()
{
    std::cout<<"PC:"<<pc<<std::endl;
    std::cout << "stack_size:" << vmStack->size() << std::endl;
    std::stack<Frame *> vm;
    while (!vmStack->empty())
    {
        vmStack->top()->printFrame();
        vm.push(vmStack->top());
        vmStack->pop();
    }

    while (!vm.empty())
    {
        vmStack->push(vm.top());
        vm.pop();
    }
}

Thread::~Thread()
{
    free(vmStack);
}
