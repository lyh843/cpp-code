#pragma once
#include <iostream>
#include <string>

class Queue {
private:
    // 使用链表实现，示例
    struct Node {
        int val;
        Node* next;
        Node(int x);  // 构造函数
    };
    Node* head;  // 队首指针
    Node* tail;  // 队尾指针
public:
    Queue();     // 构造函数
    ~Queue();    // 析构函数
    void push(int x);
    void pop();
    void query() const;
    void size() const;
};