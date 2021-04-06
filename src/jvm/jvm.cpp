#include"jvm.h"

JVM::JVM(Cmd &cmd){
    this->class_name = cmd.getClassName();
    class_loader = new ClassLoader(cmd.getClassPath(),cmd.getXjrePath());
}