#include<iostream>

struct MM_Struct {
    bool locked;
    size_t size; //如果是一段连续分配内存的开头，就保存这段连续内存区域的大小。
    int val;
    MM_Struct *nxt;
    MM_Struct() {
        locked = false;
        val = 0;
        nxt = nullptr;
        size = 0;
    }
}; // 表示一个4字节内存单元