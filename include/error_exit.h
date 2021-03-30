#pragma once
#include<iostream>

//一个简单的异常处理函数，可直接中断程序运行且打印出错信息
static inline void exit_with_massage(std::string message) {
	std::cerr << message << std::endl;
	exit(-1);
}