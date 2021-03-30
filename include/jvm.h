#pragma once
#include <iostream>
#include"cmd.h"
#include"classfile.h"
using namespace std;
class JVM
{
private:
    string classpath;
    string Xjrepath;

public:
    void satrtJVM(Cmd &cmd);
    void class_load(string filename);
};