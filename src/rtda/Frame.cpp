#include"rtda/Frame.h"
#include"error_exit.h"

Frame::Frame(u4 maxLocals,u4 maxStack){
    localVars = new LocalVars(maxLocals);
    operandStack = new OperandStack(maxStack);
}

Frame::~Frame(){
    free(localVars);
    free(operandStack);
}