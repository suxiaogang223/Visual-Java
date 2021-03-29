#include"cmd.h"

Cmd::Cmd(int argv,char *args[]){
    cmdline::parser parser;
    parser.add("help",'?',"print help message");
    parser.add("version",'v',"print version message and exit");
    parser.add<std::string>("classpath",'cp',"classpath",true,"");

    parser.parse_check(argv,args);

    this->helpFlag = parser.exist("help");
    this->versionFlag = parser.exist("version");
    this->cpOption = parser.get<std::string>("classpath");

}

bool Cmd::isHelpFlag(){
    return helpFlag;
}

bool Cmd::isVersionFlag(){
    return versionFlag;
}

std::string Cmd::getCpOption(){
    return cpOption;
}