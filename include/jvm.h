#pragma once
#include"cmd.h"
#include"classLoader.h"
#include"Thread.h"
#include"jvm_typedef.h"
#include"jvm_code.h"
#include "mem_master.h"
#include<vector>
#include<map>
//using namespace std;
class JVM
{
private:
    std::string main_class_name;//入口类
    ClassLoader* class_loader;//类加载器
    std::map<std::string,ClassFile*> classfiles;//已加载的类文件
    MemMaster *mem_master;
    std::vector<Thread*> threads;//线程
    Thread* current_thread;//当前线程
    Frame* current_frame;//当前栈帧

    // static u4 opcode_length[]; //每条指令的长度
    void interprete(u1 code);//解释字节码

    int printCount = 0;
    inline ClassFile* getClassFile(std::string classname);
    inline void printJVM();
    inline void printfClassFiles();
    inline void printThreads();

public:
    JVM(Cmd &cmd);
    void init();//初始化
    void run();//启动虚拟机
};