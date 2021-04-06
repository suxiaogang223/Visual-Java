#include"jvm.h"

JVM::JVM(Cmd &cmd){
    this->main_class_name = cmd.getClassName();
    class_loader = new ClassLoader(cmd.getClassPath(),cmd.getXjrePath());
}
void JVM::test(){//测试
    ClassFile *file = class_loader->load(main_class_name);
    file->printClassFile();
}