#include"classLoader.h"

ClassLoader::ClassLoader(string classpath,string Xjrepath){
    this->classpath = classpath;
    this->Xjrepath = Xjrepath;
}

ClassFile* ClassLoader::load(string className){

}