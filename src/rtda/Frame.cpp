#include"rtda/Frame.h"
#include"rtda_tpdef.h"

Frame::Frame(u4 maxLocals,u4 maxStack){
    localVars = new LocalVars(maxLocals);
    operandStack = new OperandStack(maxStack);
}

Frame::~Frame(){
    free(localVars);
    free(operandStack);
}