#include"cmd.h"

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
    }else if(cmd.getClassName()==""){
        std::cerr<<"please write the class which you want to run"<<std::endl;
        cmd.printUsage();
    }else{
        std::string class_path = cmd.getClassPath();
        std::string class_name = cmd.getClassName();
        if(class_path==""){
            std::cout<<class_name+" started"<<std::endl;
        }else{
            std::cout<<class_path+class_name+" statred"<<std::endl;
        }
    }
}