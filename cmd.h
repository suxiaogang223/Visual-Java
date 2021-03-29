#pragma once
#include <string>
#include "cmdline.h"


class Cmd
{
private:
    bool helpFlag;
    bool versionFlag;
    std::string cpOption;
    std::string _class;
    bool ok;
public:
    Cmd(int argc,char *argv[]);
    bool isHelpFlag();
    bool isVersionFlag();
    std::string getCpOption();
    std::string getClass();
};