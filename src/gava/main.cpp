#include"cmd.h"
#include"jvm.h"
// #include <dirent.h>

void startJVM(Cmd &cmd){
    
    JVM *jvm = new JVM(cmd);
    jvm->test();
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
    }else{
        startJVM(cmd);
    }
}