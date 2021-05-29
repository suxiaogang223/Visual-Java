#include "mem_master.h"

MemMaster::MemMaster(u4 max_size)
{
    size = INITSIZE;
    this->max_size = max_size;
    mems = (u1 *)calloc(size, sizeof(u1));
    empty_mems.push_back(new EmptyMem(0, size));
}

jobject MemMaster::newObject(ClassFile *classfile)
{
    u4 size = classfile->getSize();
    for (int i = 0; i < empty_mems.size(); i++)
    {
        if (empty_mems[i]->length >= size)
        { //分配内存
            EmptyMem *mem = empty_mems[i];
            instance.push_back(new ObjectHandle(classfile, mem->begin)); //记录位于内存的位置
            delete (mem);                                                //防止内存泄漏
            mem = new EmptyMem(mem->begin + size, mem->length - size);
            return instance.size()-1;//返回句柄的位置
        }
    }
    exit_with_massage("can't find empty_mem");
    //TODO内存不够，进行内存分配
    // if(size+NEWSIZE>max_size)
    //     exit_with_massage("heap out of size error");
    // size+=NEWSIZE;
    
    // mems = (u1*)realloc(mems,size);
    // for(int i = 0;i<empty_mems.size();i++){
    //     if(empty_mems[i]->begin+empty_mems[i]->length==size){

    //     }
    // }
}