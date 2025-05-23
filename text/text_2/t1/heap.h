#ifndef HEAP_H
#define HEAP_H
#include "mm.h"
class Heap {
private:
    MM_Struct *head;
    size_t size; // 当堆区大小不够时，需要将大小变为原来的两倍
    //你可以添加其他的私有函数
public:
    Heap(size_t _size);
    ~Heap();
    size_t GetTotalSize() {return size;}
    MM_Struct *Malloc(size_t size);
    void Free(MM_Struct *p);
    void output(MM_Struct *p);
    void setval(MM_Struct *p, int x);
};

#endif