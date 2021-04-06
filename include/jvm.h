#pragma once
#include <iostream>
#include"cmd.h"
#include"classLoader.h"
using namespace std;
class JVM
{
private:
    ClassLoader* class_loader;
    string class_name;

public:
    JVM(Cmd &cmd);
};