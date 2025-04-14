#include "heap.h"
#include <iostream>

Heap::Heap(size_t _size){
    if (_size != 0){
        MM_Struct *newnode = new MM_Struct;
        head = newnode;
        newnode->size = _size;
        MM_Struct *prev = newnode;
        for(int i = 0; i < _size / 4 - 1; i++){
            MM_Struct *newnode = new MM_Struct;
            prev->nxt = newnode;
            prev = prev->nxt;
        }
    }
    size = _size;
}
Heap::~Heap() {
    while(head){
        MM_Struct *denode = head;
        head = head->nxt;
        delete denode;
    }
    size = 0;
}
MM_Struct *Heap::Malloc(size_t size) {
    MM_Struct *curr = head;
    while(curr){
        if (curr->locked){
            curr = curr->nxt;
            continue;
        }
        if(curr->size == size){
            MM_Struct *newhead = curr;
            for(int i = 0; i < size / 4; i++){
                curr->locked = true;
                curr = curr->nxt;
            }
            return newhead;
        }
        else if(curr->size > size){
            int newsize = curr->size - size;
            MM_Struct *newnode = curr;
            curr->size = size;
            for(int i = 0; i < size / 4; i++){
                newnode->locked = true;
                newnode = newnode->nxt;
            }
            newnode->size = newsize;
            return curr;
        }
        else break;
    }
    //得扩容了，此时curr指向一个未使用的节点（头部）或空节点
    MM_Struct *newnode = new MM_Struct, *newhead = newnode, *prev = newhead;
    for(int i = 0; i < this->size / 4 - 1; i++){
        newnode = new MM_Struct;
        prev->nxt = newnode;
        prev = prev->nxt;
    }
    if(curr) curr->size += this->size;
    else newhead->size = this->size;
    MM_Struct *tail = head;
    while(tail && tail->nxt) tail = tail->nxt;
    tail->nxt = newhead;
    this->size *= 2;
    return Malloc(size);
}
void Heap::Free(MM_Struct *p) {
    //TODO
    if (!p || p->locked == false) std::cout<<"Segmentation Fault!\n";
    else if(p->size != 0)
    {
        MM_Struct *newhead = head, *lastnode = head, *tail = head, *curr = head;
        if(p == head){//如果删的是头节点
            do newhead = newhead->nxt;
            while (newhead && newhead->size == 0);//寻找新的头节点
            if(!newhead){//p是全部
                while(curr){
                    curr->locked = false;
                    curr = curr->nxt;
                }
                return;
            }
        }
        else//如果删的不是头节点
        {
            newhead = head;
            MM_Struct *prev = head;
            curr = head;
            //找到p的前置节点和后置节点，连起来。
            while(prev && prev->nxt != p) prev = prev->nxt;
            curr = prev->nxt->nxt;
            while(curr && curr->size == 0) curr = curr->nxt;
            prev->nxt = curr;
        }
        //对lastnode和tail进行定位
        lastnode = newhead;
        curr = lastnode;
        while(curr && curr->nxt){
            if(curr->nxt->size != 0){
                lastnode = curr->nxt;
            }
            curr = curr->nxt;
        }
        tail = curr;
        if(lastnode && lastnode->locked == false){//最后的一个节点未使用。
            lastnode->size += p->size;
            p->size = 0;
        }
        curr = p->nxt;
        tail->nxt = p;
        p->locked = false;
        p->val = 0;
        p->nxt = nullptr;
        tail = tail->nxt;
        while(curr && curr->size == 0){
            curr->locked = false;
            curr->val = 0;
            tail->nxt = curr;
            curr = curr->nxt;
            tail = tail->nxt;
            tail->nxt = nullptr;
        } 
        head = newhead;
    }
    else std::cout<<"Error Free!\n";
}
void Heap::output(MM_Struct *p) {
    if(!p || p->locked == false) std::cout<<"Segmentation Fault!\n";
    else if(p->size != 0){
        MM_Struct *curr = p;
        while(curr && curr->nxt && curr->nxt->size == 0){
            std::cout<<curr->val<<" ";
            curr = curr->nxt;
        }
        std::cout<<curr->val<<std::endl;
    }
    else std::cout<<p->val<<std::endl;
}
void Heap::setval(MM_Struct *p, int x) {
    if(!p || p->locked == false) std::cout<<"Segmentation Fault!\n";
    else p->val = x;
}