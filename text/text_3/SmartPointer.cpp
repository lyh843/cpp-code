#include "SmartPointer.h"

SmartPointer::SmartPointer(const SmartPointer &sptr){
    //TODO
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if(sptr.ref_cnt)
    {
        (*ref_cnt)++;
    }
}

void SmartPointer::assign(const SmartPointer &sptr){
    //TODO
    if(pointer == sptr.pointer) return;
    if(ref_cnt && (*ref_cnt) >= 1) (*ref_cnt)--;
    if(pointer && ref_cnt && (*ref_cnt) == 0)
    {
        delete pointer;
    }
    pointer = sptr.pointer;
    if(sptr.ref_cnt) 
    {
        ref_cnt = sptr.ref_cnt;
        (*ref_cnt)++;
    }
}

SmartPointer::~SmartPointer(){
    //TODO
    if(ref_cnt) (*ref_cnt)--;
    if(pointer && ref_cnt && (*ref_cnt) == 0)
    {
        delete pointer;
    }
    pointer = nullptr;
    ref_cnt = nullptr;
}
