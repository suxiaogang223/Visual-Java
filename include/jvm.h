#pragma once
#include"cmd.h"
#include"classLoader.h"
class JVM
{
private:
    ClassLoader* class_loader;
    string main_class_name;//入口类

public:
    JVM(Cmd &cmd);
    void test();//测试函数
};