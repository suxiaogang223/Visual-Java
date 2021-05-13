#include"OperandStack.h"

OperandStack::OperandStack(u2 maxStack){
    this->maxStack = maxStack;
    if(maxStack>0)
        stack = new u4[maxStack]();//new的同时初始化
    index = 0;
}

void OperandStack::printOperandStack(){
    std::cout<<"op_stack_length:"<<index<<std::endl;
    for(u4 i = index-1;i>=0;i--)
        std::cout<<stack[i]<<std::endl;
}

void OperandStack::push(u4 operand){
    if(index==maxStack)
        exit_with_massage("operandStack overflow");//异常处理 操作数栈溢出
    stack[index++] = operand;
}

void OperandStack::pop(){
    if(index==0)
        exit_with_massage("operandStack is empty");
    index--;
}

u4 OperandStack::getTop(){
    if(index==0)
        exit_with_massage("operandStack is empty");
    return stack[index-1];
}

OperandStack::~OperandStack(){
    free(stack);
}

