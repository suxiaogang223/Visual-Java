#pragma once
#include <iostream>
#include<dirent.h>
#include"error_exit.h"

class Cmd
{
private:
    bool helpFlag = false;
    bool versionFlag = false;
    std::string className = "";//类名
    std::string classPath = "";//用户路径
    std::string XjrePath = "";//运行路径

    bool string_equal(char* s1,std::string s2){
        for(int i = 0;i<s2.size();i++)
            if(s1[i]!=s2[i])
                return false;
        return true;
    }
public:
    bool parse(int argc,char* argv[]);
    bool isHelp();
    bool isVersion();
    std::string getClassName();
    std::string getClassPath();
    std::string getXjrePath();
    void printUsage();
    void printVersion();
};