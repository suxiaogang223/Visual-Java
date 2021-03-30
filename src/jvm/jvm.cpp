#include"jvm.h"
void JVM::satrtJVM(Cmd &cmd){
    classpath = cmd.getClassPath();
    Xjrepath = cmd.getXjrePath();
    class_load(cmd.getClassName());
}

void JVM::class_load(string filename){
    string class_file_path = classpath+filename+".class";//类文件的完全路径
    ClassFile *class_file = new ClassFile(class_file_path);
    class_file->printClassFile();
}