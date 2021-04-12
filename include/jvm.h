#pragma once
#include"cmd.h"
#include"classfile/classLoader.h"
#include"rtda/Thread.h"
#include"jvm_typedef.h"
#include"jvm_code.h"
#include<vector>
#include<map>
using namespace std;
class JVM
{
private:
    ClassLoader* class_loader;
    string main_class_name;//入口类
    map<string,ClassFile*> classfiles;//存储
    vector<Thread*> threads;//线程
    Thread* current_thread;
    void interprete(u1 code);
    

public:
    JVM(Cmd &cmd);
    void init();//初始化
    void run();//启动虚拟机
};