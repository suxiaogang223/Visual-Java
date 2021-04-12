#pragma once
#include <iostream>
#include <map>
#include <cstring>
#include <fstream>
#include "classfile_typedef.h"
#include "classfile_constants.h"
#include "error_exit.h"
using namespace std;

class ClassFile
{
private:
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;//常量池个数
    CpInfo *constant_pools;//常量池
    u2 access_flags;//类的标识
    u2 this_class;
    u2 super_class;//父类
    u2 interfaces_count;//接口个数
    InterfacesInfo *interfaces;//接口信息
    u2 fields_count;//域个数
    FieldInfo *fields;//域信息
    u2 methods_count;//方法个数
    MethodInfo *methods;//方法信息
    u2 attributes_count;
    AttributeInfo *attributes;


    map<string, fieldType> static_fields;//存储static类型的filed
	void init_static_fields();//static变量在类加载的时候初始化
	std::fstream f;
	u1 getU1();//按字节读取
	u2 getU2();
	u4 getU4();
	
	
	void parseFile();
	void parseConstantPools();
	void parseInterfaces();
	void parseFields();
	void parseMethods();
	void parseAttributes();

	//输出函数
	void printConstantPools();
	void printFlags(u2 flags);
	void printInterfaces();
	void printFields();
	void printMethods();

public:
	ClassFile(string class_file_path);
	Code_attribute* getMethodByNameAndType(string name,string type);
	fieldType getField(string name);
	void setField(string name, fieldType value);
	void printClassFile();
	~ClassFile();
};