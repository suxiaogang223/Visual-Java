#include"rtda/Stack.h"
#include"error_exit.h"

Stack::Stack(u4 maxSize){
    this->maxSize = maxSize;
    _top = NULL;
    size = 0;
}

void Stack::push(Frame *frame){
    if(size>=maxSize)
        exit_with_massage("VMStack overflow");
    // if(_top!=NULL)
    frame->lower = _top;
    _top = frame;
    size++;
    
}

void Stack::pop(){
    if(_top==NULL)
        exit_with_massage("VMStack is empty");
    Frame* lower = _top->lower;
    free(_top);//释放内存
    _top = lower;
    size--;
}

Frame* Stack::top(){
    if(_top==NULL)
        exit_with_massage("VMStack is empty");
    return _top;
}

Stack::~Stack(){
    //TODO
}