#include "cmd.h"

int main(int argv,char* args[]){
    Cmd *cmd = new Cmd(argv,args);
    if(cmd->isHelpFlag()){
        std::cout<<"help"<<std::endl;
    }else if(cmd->isVersionFlag()){
        std::cout<<"version 0.1"<<std::endl;
    }else{
        std::cout<<"startJvm"<<std::endl;
    }
}