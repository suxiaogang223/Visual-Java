#include"classLoader.h"

ClassLoader::ClassLoader(string classpath,string Xjrepath){
    this->classpath = classpath;
    this->Xjrepath = Xjrepath;
}

ClassFile* ClassLoader::load(string className){
    string class_file_classpath = classpath+className+".class";
    string class_file_jrepath = Xjrepath+className+".name";
    fstream f1,f2;
    f1.open(class_file_classpath, ios::in | ios::binary);
    f2.open(class_file_jrepath,ios::in | ios::binary);
    if(f1)
        return new ClassFile(class_file_classpath);
    else if(f2){
        return new ClassFile(class_file_jrepath);
    }else{
        exit_with_massage("can't find class file "+className);
        return NULL;//为了不警告:(
    }
}