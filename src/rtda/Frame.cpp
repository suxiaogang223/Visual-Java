#include"rtda/Frame.h"
#include"error_exit.h"

Frame::Frame(u4 maxLocals,u4 maxStack,u4 code_length,char* codes){
    localVars = new LocalVars(maxLocals);
    operandStack = new OperandStack(maxStack);
    this->code_length = code_length;
    this->codes = codes;
    lower = NULL;
}

char Frame::getCode(u4 pc){
    if(pc>=code_length)
        exit_with_massage("pc out of code length");
    return codes[pc];
}

Frame::~Frame(){
    free(localVars);
    free(operandStack);
}