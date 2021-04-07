# Visual-Java" 

TODO typedef_translate.h 最后需要被删除
在虚拟机内部存储的所有变量都是u4（4字节无符号数），在此我们设为（typedef unsigned int u4;），在使用时需要通过联合类型进行类型转换。
而在显示时需要提供一个显示各种类型的选项



## 堆的设计

将classfile.h划归到classLoader模块，堆使用可管理内存式的方式管理。