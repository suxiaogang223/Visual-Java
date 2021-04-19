#include"cmd.h"
#include"jvm.h"
// #include <dirent.h>

void startJVM(Cmd &cmd){
    
    JVM jvm(cmd);//创建一个虚拟机对象
    jvm.init();//初始化
    jvm.run();//开始运行
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