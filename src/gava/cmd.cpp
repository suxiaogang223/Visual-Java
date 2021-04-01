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
        }else if(string_equal(argv[i],"-Xjre")){
            if(XjrePath!="")
                return false;
            XjrePath = argv[++i];
        }else{
            if(className!="")
                return false;
            className = argv[i];
        }
    }
    
    if(className=="")
        return false;
    if(XjrePath=="")
        //return false;
        XjrePath = "C:\\Users\\lishizhen\\Desktop\\Visual-Java\\gre\\";//将gre（gava runtime environment）暂时设置
    if(classPath=="")
        classPath = "./";
    if(classPath.back()!='/')
        classPath = classPath+"/";
    if(!opendir(classPath.c_str()))
        exit_with_massage("can't find dir: "+classPath);
    if(!opendir(XjrePath.c_str()))
        exit_with_massage("can't find dir: "+XjrePath);
    return true;
}

std::string Cmd::getClassName(){
    return className;
}

std::string Cmd::getClassPath(){
    return classPath;
}

std::string Cmd::getXjrePath(){
    return XjrePath;
}

bool Cmd::isHelp(){
    return helpFlag;
}

bool Cmd::isVersion(){
    return versionFlag;
}

void Cmd::printUsage(){
    std::cout<<"Usage: gava [-options] class [args]"<<std::endl;
    std::cout<<"options:"<<std::endl;
    std::cout<<"-v/-version       print version message and exit"<<std::endl;
    std::cout<<"-?/-help          print usage message and exit"<<std::endl;
    std::cout<<"-cp/-classpath    classpath"<<std::endl;
    std::cout<<"-Xjre             path to jre"<<std::endl; 
}

void Cmd::printVersion(){
    std::cout<<"gava 0.1"<<std::endl;
}