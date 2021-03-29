#include "cmd.h"

bool Cmd::parse(int argc, char *argv[])//处理命令行
{
    if (argc == 1)
        return false;
    for (int i = 1; i < argc; i++)
    {
        if (string_equal(argv[i],"-?")||string_equal(argv[i],"-help"))
        {
            if (helpFlag)
                return false;
            helpFlag = true;
            return true;
        }
        else if (string_equal(argv[i],"-version"))
        {
            if (versionFlag)
                return false;
            versionFlag = true;
            return true;
        }
        else if (string_equal(argv[i],"-cp")||string_equal(argv[i],"-classpath")){
            if(classPath!="")
                return false;
            classPath = argv[++i];
        }else{
            if(className!="")
                return false;
            className = argv[i];
        }
    }
    return true;
}

std::string Cmd::getClassName(){
    return className;
}

std::string Cmd::getClassPath(){
    return classPath;
}

bool Cmd::isHelp(){
    return helpFlag;
}

bool Cmd::isVersion(){
    return versionFlag;
}

void Cmd::printUsage(){
    std::cout<<"Usage: gava [-options] class [args]"<<std::endl;
    std::out<<"options:"<<std::endl;
    std::cout<<"-v/-version       print version message and exit"<<std::endl;
    std::cout<<"-?/-help          print usage message and exit"<<std::endl;
    std::cout<<"-cp/-classpath    classpath"<<std::endl;
    
}

void Cmd::printVersion(){
    std::cout<<"gava 0.1"<<std::endl;
}