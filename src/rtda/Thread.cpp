#include "Thread.h"
#include "error_exit.h"

Thread::Thread(u4 maxSize)
{
    vmStack = new std::stack<Frame *>();
    pc_stack = new std::stack<u4>();
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
    pc_stack->push(pc);
    pc = 0;
}

void Thread::popFrame()
{
    vmStack->pop();
    pc = pc_stack->top();
    pc_stack->pop();
}

bool Thread::isEmpty()
{
    return vmStack->empty();
}
Frame* Thread::getTop()
{
    return vmStack->top();
}

void Thread::printThread()
{
    std::cout << "PC:" << pc << std::endl;
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
