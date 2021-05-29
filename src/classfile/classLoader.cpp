#include"classLoader.h"

ClassLoader::ClassLoader(std::string classpath,std::string Xjrepath){
    this->classpath = classpath;
    this->Xjrepath = Xjrepath;
}

ClassFile* ClassLoader::load(std::string className){
    std::string class_file_classpath = classpath+className+".class";
    std::string class_file_jrepath = Xjrepath+className+".class";
    std::cout<<class_file_classpath<<" "<<class_file_jrepath<<std::endl;
    std::fstream f1,f2;
    f1.open(class_file_classpath, std::ios::in | std::ios::binary);
    f2.open(class_file_jrepath,std::ios::in | std::ios::binary);
    if(f1)
        return new ClassFile(class_file_classpath);
    else if(f2){
        return new ClassFile(class_file_jrepath);
    }else{
        exit_with_massage("can't find class file "+className);
        return NULL;//为了不警告:(
    }
}