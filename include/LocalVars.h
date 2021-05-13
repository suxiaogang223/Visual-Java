#pragma once
#include"jvm_typedef.h"
#include"error_exit.h"

class LocalVars
{
private:
    u2 maxLocal;
    u4 *localvars;

public:
    LocalVars(u2 maxLocal);
    void printLocalVars();
    void store(u2 index,u4 localvar);
    u4 load(u2 index);
    ~LocalVars();
};