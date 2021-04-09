#include"classfile.h"
#include"error_exit.h"

class ClassLoader{
private:
    string classpath;
    string Xjrepath;
public:
    ClassLoader(string classpath,string Xjrepath);
    ClassFile* load(string className);
};