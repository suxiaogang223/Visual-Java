#include"jvm.h"

JVM::JVM(Cmd &cmd){
    this->main_class_name = cmd.getClassName();
    class_loader = new ClassLoader(cmd.getClassPath(),cmd.getXjrePath());
}


void JVM::init(){
    ClassFile* main_class = class_loader->load(main_class_name);
    classfiles.insert(pair<string,ClassFile*>(main_class_name,main_class));
    Thread* main_thread = new Thread(1024);//虚拟机栈最大暂时设置为1024
    threads.push_back(main_thread);
    current_thread = main_thread;
    Code_attribute* main_method_code =  main_class->getMethodByNameAndType("main","([Ljava/lang/String;)V");
    Frame* main_frame = new Frame(main_method_code->max_locals,main_method_code->max_stack,main_method_code->code_length,main_method_code->codes);
    main_thread->pushFrame(main_frame);
}

void JVM::run(){
    string commend;
    u4 opcode_length[] = JVM_OPCODE_LENGTH_INITIALIZER;//每条指令的长度
    while (cin>>commend)
    {
        if(!current_thread->currentFrame()){
            cout<<"JVM Over"<<endl;//程序执行完毕
            break;
        }else if(commend =="next"){
            u4 pc = current_thread->getPC();
            Frame* current_frame = current_thread->currentFrame();
            unsigned char code = current_frame->getCode(pc);
            interprete(code);//解析指令
            pc+=opcode_length[code];
            current_thread->setPC(pc);//设置pc
        }else if(commend =="end"){
            cout<<"JVM End"<<endl;
            break;
        }else{
            cout<<"Unknow Commend"<<endl;
        }
    }
    
}

void JVM::interprete(char code){
    cout<<hex<<code<<endl;//todo
}