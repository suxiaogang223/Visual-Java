#include"rtda/LocalVars.h"
#include"error_exit.h"

LocalVars::LocalVars(u4 maxLocal){
    this->maxLocal = maxLocal;
    localvars = new u4[maxLocal]();//new的同时初始化
}

void LocalVars::store(u4 index,u4 localvar){
    if(index>=maxLocal||index<0)
        exit_with_massage("lcoalVars overstep : "+index);
    localvars[index] = localvar;
}

u4 LocalVars::load(u4 index){
    if(index>=maxLocal||index<0)
        exit_with_massage("lcoalVars overstep : "+index);
    return localvars[index];
}

LocalVars::~LocalVars(){
    free(localvars);
}