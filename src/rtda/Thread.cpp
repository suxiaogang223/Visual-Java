#include "Thread.h"
#include "error_exit.h"

Thread::Thread(u4 maxSize)
{
    stack = new Stack(maxSize);
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
    return stack->top();
}

void Thread::pushFrame(Frame *frame)
{
    stack->push(frame);
}

void Thread::popFrame()
{
    stack->pop();
}

void Thread::printThread()
{
    std::cout<<"PC:"<<pc<<std::endl;
    std::cout << "stack_size:" << stack->get_size() << std::endl;
    std::stack<Frame *> vm;
    while (!stack->empty())
    {
        stack->top()->printFrame();
        vm.push(stack->top());
        stack->pop();
    }

    while (!vm.empty())
    {
        stack->push(vm.top());
        vm.pop();
    }
}

Thread::~Thread()
{
    free(stack);
}
