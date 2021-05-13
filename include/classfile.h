#pragma once
#include <iostream>
#include <map>
#include <cstring>
#include <fstream>
#include "classfile_typedef.h"
#include "classfile_constants.h"
#include "error_exit.h"
//using namespace std;

class ClassFile
{
private:
    u4 magic;//虚拟机的魔数 为十六进制数 cafe babe，一个菜蛋
	u2 minor_version;//副版本号
	u2 major_version;//主版本号
	u2 constant_pool_count;//常量池的数量
	CpInfo* constant_pools;//常量池
	u2 access_flags;// 访问标志 如public peivate interface
	u2 this_class;//类索引
	u2 super_class;//父类索引
	u2 interfaces_count;//接口计数器
	InterfacesInfo* interfaces;//接口
	u2 fields_count;//字段计数器
	FieldInfo* fields;//字段
	u2 methods_count;//方法计数器
	MethodInfo* methods;//方法
	u2 attributes_count;//属性表计数器
	AttributeInfo* attributes;//属性表


    std::map<std::string, fieldType> static_fields;//存储static类型的filed
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
	ClassFile(std::string class_file_path);
	Code_attribute* getMethodByNameAndType(std::string name,std::string type);
	fieldType getField(std::string name);
	void setField(std::string name, fieldType value);
	byte_32 getConstantByte32(u2 index);
	byte_64 getConstantByte64(u2 index);
	void printClassFile();
	~ClassFile();
};