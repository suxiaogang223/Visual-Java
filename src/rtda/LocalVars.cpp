#include"LocalVars.h"

LocalVars::LocalVars(u2 maxLocal){
    this->maxLocal = maxLocal;
    localvars = new u4[maxLocal]();//new的同时初始化
}

void LocalVars::printLocalVars(){
    std::cout<<"local_vars_length:"<<maxLocal<<std::endl;
    for(int i = 0;i<maxLocal;i++)
        std::cout<<localvars[i]<<std::endl;
}

void LocalVars::store(u2 index,u4 localvar){
    if(index>=maxLocal||index<0)
        exit_with_massage("lcoalVars overstep : "+index);
    localvars[index] = localvar;
}

u4 LocalVars::load(u2 index){
    if(index>=maxLocal||index<0)
        exit_with_massage("lcoalVars overstep : "+index);
    return localvars[index];
}

LocalVars::~LocalVars(){
    free(localvars);
}