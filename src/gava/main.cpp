#include"cmd.h"
#include <dirent.h>

void startJVM(Cmd &cmd){
    
    std::cout<<cmd.getClassName()<<" "<<cmd.getClassPath()<<" "<<cmd.getXjrePath();
}

int main(int argc,char* argv[]){
    Cmd cmd;

    if(!cmd.parse(argc,argv)){
        std::cerr<<"pelease write the right args"<<std::endl;
        cmd.printUsage();
        return 0;
    }else if(cmd.isHelp()){
        cmd.printUsage();
        return 0;
    }else if(cmd.isVersion()){
        cmd.printVersion();
        return 0;
    }else if(!opendir(cmd.getClassPath().c_str())){
        std::cerr<< cmd.getClassPath()<<" doesn't exist"<<std::endl;
        return 0;
    }else if(!opendir(cmd.getXjrePath().c_str())){
        std::cerr<< cmd.getXjrePath()<<" doesn't exist"<<std::endl;
        return 0;
    }else{
        startJVM(cmd);
    }
}