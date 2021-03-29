#pragma
#include <iostream>

class Cmd
{
private:
    bool helpFlag = false;
    bool versionFlag = false;
    std::string className = "";
    std::string classPath = "";

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
    void printUsage();
    void printVersion();
};