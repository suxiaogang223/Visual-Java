#pragma once
#include "Frame.h"
class stack
{
private:
    unsigned int maxSize;
    unsigned int size;
    Frame *top;
};