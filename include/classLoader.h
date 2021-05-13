#include"classfile.h"
#include"error_exit.h"

class ClassLoader{
private:
    std::string classpath;
    std::string Xjrepath;
public:
    ClassLoader(std::string classpath,std::string Xjrepath);
    ClassFile* load(std::string className);
};