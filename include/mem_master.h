#pragma once
#include "jvm_typedef.h"
#include "classfile.h"
#include <vector>
#include <cstdlib>

struct EmptyMem
{
    u4 begin;
    u4 length;
    EmptyMem(u4 b, u4 l) : begin(b), length(l) {}
};

struct ObjectHandle
{
    ClassFile *classfile;
    u4 address;
    ObjectHandle(ClassFile *classfile, u4 address) : classfile(classfile), address(address) {}
};

//内存管理器，将内存中的空闲地址作为一个二元组存起来，在分配内存时，使用首次适应法。
class MemMaster
{
private:
    static const u4 INITSIZE = 1024;//设定初始内存大小 1kb
    static const u4 NEWSIZE = 512; //每次扩展内存分配的内存
    u4 max_size; //最大内存
    u4 size;     //当前内存
    std::vector<struct EmptyMem *> empty_mems;
    std::vector<struct ObjectHandle *> instance;
    u1 *mems;
    // void add_empty_mem(struct EmptyMem * mem);
    // TODO: 垃圾回收算法
public:
    MemMaster(u4 max_size);
    jobject newObject(ClassFile *classfile);
    void printHeap();
};