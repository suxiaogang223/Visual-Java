#pragma once
#include"cmd.h"
#include"classfile/classLoader.h"
#include"rtda/Thread.h"
#include<vector>
#include<map>
class JVM
{
private:
    ClassLoader* class_loader;
    string main_class_name;//入口类
    std::map<string,ClassFile*> classfiles;//存储
    std::vector<Thread*> threads;//线程

public:
    JVM(Cmd &cmd);
    void start(bool isVisualable);
    void test();//测试函数
};