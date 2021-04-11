#include "jvm.h"

JVM::JVM(Cmd &cmd)
{
    this->main_class_name = cmd.getClassName();
    class_loader = new ClassLoader(cmd.getClassPath(), cmd.getXjrePath());
}

void JVM::init()
{
    ClassFile *main_class = class_loader->load(main_class_name);
    classfiles.insert(pair<string, ClassFile *>(main_class_name, main_class));
    Thread *main_thread = new Thread(1024); //虚拟机栈最大暂时设置为1024
    threads.push_back(main_thread);
    current_thread = main_thread;
    Code_attribute *main_method_code = main_class->getMethodByNameAndType("main", "([Ljava/lang/String;)V");
    Frame *main_frame = new Frame(main_method_code->max_locals, main_method_code->max_stack, main_method_code->code_length, main_method_code->codes);
    main_thread->pushFrame(main_frame);
}

void JVM::run()
{
    string commend;
    u4 opcode_length[] = JVM_OPCODE_LENGTH_INITIALIZER; //每条指令的长度
    while (cin >> commend)
    {
        if (!current_thread->currentFrame())
        {
            cout << "JVM Over" << endl; //程序执行完毕
            break;
        }
        else if (commend == "next")
        {
            u4 pc = current_thread->getPC();
            Frame *current_frame = current_thread->currentFrame();
            u1 code = (u1)current_frame->getCode(pc);
            interprete(code); //解析指令
            pc += opcode_length[code];
            current_thread->setPC(pc); //设置pc
        }
        else if (commend == "end")
        {
            cout << "JVM End" << endl;
            break;
        }
        else
        {
            cout << "Unknow Commend" << endl;
        }
    }
}

void JVM::interprete(u1 code)//这个函数可以说是虚拟机中最重要的函数，他很长，但是我还没有找到足够优雅的方式进行重构:(
{
    switch (code)
    {
    case nop: //什么都不做

    case aconst_null: //将null推送至栈顶

    case iconst_m1: //将int型-1推送至栈顶

    case iconst_0: //将int型0推送至栈顶

    case iconst_1: //将int型1推送至栈顶

    case iconst_2: //将int型2推送至栈顶

    case iconst_3: //将int型3推送至栈顶

    case iconst_4: //将int型4推送至栈顶

    case iconst_5: //将int型5推送至栈顶

    case lconst_0: //将long型0推送至栈顶

    case lconst_1: //将long型1推送至栈顶

    case fconst_0: //将float型0推送至栈顶

    case fconst_1: //将float型1推送至栈顶

    case fconst_2: //将float型2推送至栈顶

    case dconst_0: //将double型0推送至栈顶

    case dconst_1: //将double型1推送至栈顶

    case bipush: //将单字节的常量值(-128~127)推送至栈顶

    case sipush: //将一个短整型常量值(-32768~32767)推送至栈顶

    case ldc: //将int,float或String型常量值从常量池中推送至栈顶

    case ldc_w: //将int,float或String型常量值从常量池中推送至栈顶（宽索引）

    case ldc2_w: //将long或double型常量值从常量池中推送至栈顶（宽索引）

    case iload: //将指定的int型本地变量

    case lload: //将指定的long型本地变量

    case fload: //将指定的float型本地变量

    case dload: //将指定的double型本地变量

    case aload: //将指定的引用类型本地变量

    case iload_0: //将第一个int型本地变量

    case iload_1: //将第二个int型本地变量

    case iload_2: //将第三个int型本地变量

    case iload_3: //将第四个int型本地变量

    case lload_0: //将第一个long型本地变量

    case lload_1: //将第二个long型本地变量

    case lload_2: //将第三个long型本地变量

    case lload_3: //将第四个long型本地变量

    case fload_0: //将第一个float型本地变量

    case fload_1: //将第二个float型本地变量

    case fload_2: //将第三个float型本地变量

    case fload_3: //将第四个float型本地变量

    case dload_0: //将第一个double型本地变量

    case dload_1: //将第二个double型本地变量

    case dload_2: //将第三个double型本地变量

    case dload_3: //将第四个double型本地变量

    case aload_0: //将第一个引用类型本地变量

    case aload_1: //将第二个引用类型本地变量

    case aload_2: //将第三个引用类型本地变量

    case aload_3: //将第四个引用类型本地变量

    case iaload: //将int型数组指定索引的值推送至栈顶

    case laload: //将long型数组指定索引的值推送至栈顶

    case faload: //将float型数组指定索引的值推送至栈顶

    case daload: //将double型数组指定索引的值推送至栈顶

    case aaload: //将引用型数组指定索引的值推送至栈顶

    case baload: //将boolean或byte型数组指定索引的值推送至栈顶

    case caload: //将char型数组指定索引的值推送至栈顶

    case saload: //将short型数组指定索引的值推送至栈顶

    case istore: //将栈顶int型数值存入指定本地变量

    case lstore: //将栈顶long型数值存入指定本地变量

    case fstore: //将栈顶float型数值存入指定本地变量

    case dstore: //将栈顶double型数值存入指定本地变量

    case astore: //将栈顶引用型数值存入指定本地变量

    case istore_0: //将栈顶int型数值存入第一个本地变量

    case istore_1: //将栈顶int型数值存入第二个本地变量

    case istore_2: //将栈顶int型数值存入第三个本地变量

    case istore_3: //将栈顶int型数值存入第四个本地变量

    case lstore_0: //将栈顶long型数值存入第一个本地变量

    case lstore_1: //将栈顶long型数值存入第二个本地变量

    case lstore_2: //将栈顶long型数值存入第三个本地变量

    case lstore_3: //将栈顶long型数值存入第四个本地变量

    case fstore_0: //将栈顶float型数值存入第一个本地变量

    case fstore_1: //将栈顶float型数值存入第二个本地变量

    case fstore_2: //将栈顶float型数值存入第三个本地变量

    case fstore_3: //将栈顶float型数值存入第四个本地变量

    case dstore_0: //将栈顶double型数值存入第一个本地变量

    case dstore_1: //将栈顶double型数值存入第二个本地变量

    case dstore_2: //将栈顶double型数值存入第三个本地变量

    case dstore_3: //将栈顶double型数值存入第四个本地变量

    case astore_0: //将栈顶引用型数值存入第一个本地变量

    case astore_1: //将栈顶引用型数值存入第二个本地变量

    case astore_2: //将栈顶引用型数值存入第三个本地变量

    case astore_3: //将栈顶引用型数值存入第四个本地变量

    case iastore: //将栈顶int型数值存入指定数组的指定索引位置

    case lastore: //将栈顶long型数值存入指定数组的指定索引位置

    case fastore: //将栈顶float型数值存入指定数组的指定索引位置

    case dastore: //将栈顶double型数值存入指定数组的指定索引位置

    case aastore: //将栈顶引用型数值存入指定数组的指定索引位置

    case bastore: //将栈顶boolean或byte型数值存入指定数组的指定索引位置

    case castore: //将栈顶char型数值存入指定数组的指定索引位置

    case sastore: //将栈顶short型数值存入指定数组的指定索引位置

    case pop: //将栈顶数值弹出(数值不能是long或double类型的)

    case pop2: //将栈顶的一（long或double类型的)或两个数值弹出（其它）

    case dup_: //复制栈顶数值并将复制值压入栈顶

    case dup_x1: //复制栈顶数值并将两个复制值压入栈顶

    case dup_x2: //复制栈顶数值并将三个（或两个）复制值压入栈顶

    case dup2_: //复制栈顶一个（long或double类型的)或两个（其它）数值并将复制值压入栈顶

    case dup2_x1: //dup_x1指令的双倍版本

    case dup2_x2: //dup_x2指令的双倍版本

    case swap_: //将栈最顶端的两个数值互换(数值不能是long或double类型的)

    case iadd: //将栈顶两int型数值相加并将结果压入栈顶

    case ladd: //将栈顶两long型数值相加并将结果压入栈顶

    case fadd: //将栈顶两float型数值相加并将结果压入栈顶

    case dadd: //将栈顶两double型数值相加并将结果压入栈顶

    case is: //将栈顶两int型数值相减并将结果压入栈顶

    case ls: //将栈顶两long型数值相减并将结果压入栈顶

    case fs: //将栈顶两float型数值相减并将结果压入栈顶

    case ds: //将栈顶两double型数值相减并将结果压入栈顶

    case imul: //将栈顶两int型数值相乘并将结果压入栈顶

    case lmul: //将栈顶两long型数值相乘并将结果压入栈顶

    case fmul: //将栈顶两float型数值相乘并将结果压入栈顶

    case dmul: //将栈顶两double型数值相乘并将结果压入栈顶

    case idiv: //将栈顶两int型数值相除并将结果压入栈顶

    case ldiv_: //将栈顶两long型数值相除并将结果压入栈顶

    case fdiv: //将栈顶两float型数值相除并将结果压入栈顶

    case ddiv: //将栈顶两double型数值相除并将结果压入栈顶

    case irem: //将栈顶两int型数值作取模运算并将结果压入栈顶

    case lrem: //将栈顶两long型数值作取模运算并将结果压入栈顶

    case frem: //将栈顶两float型数值作取模运算并将结果压入栈顶

    case drem: //将栈顶两double型数值作取模运算并将结果压入栈顶

    case ineg: //将栈顶int型数值取负并将结果压入栈顶

    case lneg: //将栈顶long型数值取负并将结果压入栈顶

    case fneg: //将栈顶float型数值取负并将结果压入栈顶

    case dneg: //将栈顶double型数值取负并将结果压入栈顶

    case ishl: //将int型数值左移位指定位数并将结果压入栈顶

    case lshl: //将long型数值左移位指定位数并将结果压入栈顶

    case ishr: //将int型数值右（符号）移位指定位数并将结果压入栈顶

    case lshr: //将long型数值右（符号）移位指定位数并将结果压入栈顶

    case iushr: //将int型数值右（无符号）移位指定位数并将结果压入栈顶

    case lushr: //将long型数值右（无符号）移位指定位数并将结果压入栈顶

    case iand: //将栈顶两int型数值作“按位与”并将结果压入栈顶

    case land: //将栈顶两long型数值作“按位与”并将结果压入栈顶

    case ior: //将栈顶两int型数值作“按位或”并将结果压入栈顶

    case lor: //将栈顶两long型数值作“按位或”并将结果压入栈顶

    case ixor: //将栈顶两int型数值作“按位异或”并将结果压入栈顶

    case lxor: //将栈顶两long型数值作“按位异或”并将结果压入栈顶

    case iinc: //将指定int型变量增加指定值（i++,i–,i+=2）

    case i2l: //将栈顶int型数值强制转换成long型数值并将结果压入栈顶

    case i2f: //将栈顶int型数值强制转换成float型数值并将结果压入栈顶

    case i2d: //将栈顶int型数值强制转换成double型数值并将结果压入栈顶

    case l2i: //将栈顶long型数值强制转换成int型数值并将结果压入栈顶

    case l2f: //将栈顶long型数值强制转换成float型数值并将结果压入栈顶

    case l2d: //将栈顶long型数值强制转换成double型数值并将结果压入栈顶

    case f2i: //将栈顶float型数值强制转换成int型数值并将结果压入栈顶

    case f2l: //将栈顶float型数值强制转换成long型数值并将结果压入栈顶

    case f2d: //将栈顶float型数值强制转换成double型数值并将结果压入栈顶

    case d2i: //将栈顶double型数值强制转换成int型数值并将结果压入栈顶

    case d2l: //将栈顶double型数值强制转换成long型数值并将结果压入栈顶

    case d2f: //将栈顶double型数值强制转换成float型数值并将结果压入栈顶

    case i2b: //将栈顶int型数值强制转换成byte型数值并将结果压入栈顶

    case i2c: //将栈顶int型数值强制转换成char型数值并将结果压入栈顶

    case i2s: //将栈顶int型数值强制转换成short型数值并将结果压入栈顶

    case lcmp: //比较栈顶两long型数值大小，并将结果（1，0，-1）压入栈顶

    case fcmpl: //比较栈顶两float型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将-1压入栈顶

    case fcmpg: //比较栈顶两float型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将1压入栈顶

    case dcmpl: //比较栈顶两double型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将-1压入栈顶

    case dcmpg: //比较栈顶两double型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将1压入栈顶

    case ifeq: //当栈顶int型数值等于0时跳转

    case ifne: //当栈顶int型数值不等于0时跳转

    case iflt: //当栈顶int型数值小于0时跳转

    case ifge: //当栈顶int型数值大于等于0时跳转

    case ifgt: //当栈顶int型数值大于0时跳转

    case ifle: //当栈顶int型数值小于等于0时跳转

    case if_icmpeq: //比较栈顶两int型数值大小，当结果等于0时跳转

    case if_icmpne: //比较栈顶两int型数值大小，当结果不等于0时跳转

    case if_icmplt: //比较栈顶两int型数值大小，当结果小于0时跳转

    case if_icmpge: //比较栈顶两int型数值大小，当结果大于等于0时跳转

    case if_icmpgt: //比较栈顶两int型数值大小，当结果大于0时跳转

    case if_icmple: //比较栈顶两int型数值大小，当结果小于等于0时跳转

    case if_acmpeq: //比较栈顶两引用型数值，当结果相等时跳转

    case if_acmpne: //比较栈顶两引用型数值，当结果不相等时跳转

    case goto_: //无条件跳转

    case jsr: //跳转至指定16位offset位置，并将jsr下一条指令地址压入栈顶

    case ret: //返回至本地变量

    case tableswitch: //用于switch条件跳转，case值连续（可变长度指令）

    case lookupswitch: //用于switch条件跳转，case值不连续（可变长度指令）

    case ireturn: //从当前方法返回int

    case lreturn: //从当前方法返回long

    case freturn: //从当前方法返回float

    case dreturn: //从当前方法返回double

    case areturn: //从当前方法返回对象引用

    case return_: //从当前方法返回void

    case getstatic: //获取指定类的静态域，并将其值压入栈顶

    case putstatic: //为指定的类的静态域赋值

    case getfield: //获取指定类的实例域，并将其值压入栈顶

    case putfield: //为指定的类的实例域赋值

    case invokevirtual: //调用实例方法

    case invokespecial: //调用超类构造方法，实例初始化方法，私有方法

    case invokestatic: //调用静态方法

    case invokeinterface: //调用接口方法

    //case –: //无此指令

    case new_: //创建一个对象，并将其引用值压入栈顶

    case newarray: //创建一个指定原始类型（如int, float, char…）的数组，并将其引用值压入栈顶

    case anewarray: //创建一个引用型（如类，接口，数组）的数组，并将其引用值压入栈顶

    case arraylength: //获得数组的长度值并压入栈顶

    case athrow: //将栈顶的异常抛出

    case checkcast: //检验类型转换，检验未通过将抛出ClassCastException

    case instanceof: //检验对象是否是指定的类的实例，如果是将1压入栈顶，否则将0压入栈顶

    case monitorenter: //获得对象的锁，用于同步方法或同步块

    case monitorexit: //释放对象的锁，用于同步方法或同步块

    case wide: //<待补充>

    case multianewarray: //创建指定类型和指定维度的多维数组（执行该指令时，操作栈中必须包含各维度的长度值），并将其引用值压入栈顶

    case ifnull: //为null时跳转

    case ifnonnull: //不为null时跳转

    case goto_w: //无条件跳转（宽索引）

    case jsr_w: //跳转至指定32位offset位置，并将jsr_w下一条指令地址压入栈顶

    default:
        break;
    }
}