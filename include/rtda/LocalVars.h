#pragma once
#include "rtda_tpdef.h"

class LocalVars
{
private:
    u4 maxLocal;
    u4 *localvars;

public:
    LocalVars(u4 maxLocal);
    void store(u4 index,u4 localvar);
    u4 load(u4 index);
    ~LocalVars();
};