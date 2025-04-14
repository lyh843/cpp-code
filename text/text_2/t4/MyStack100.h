// MyStack100.h
#include<iostream>
using namespace std;
class MyStack {
    // 用链表实现“栈”
private:
    struct Node
    { 
        char content;
        Node *next;
    } *top;
    int sz;
public:
    MyStack(){sz = 0; top = NULL;}  // 构造函数
    ~MyStack() // 析构函数，你需要在这里归还额外申请的资源
    { 
        while (top != NULL)
        { 
            Node *p = top;   
            top = top->next;
            delete p;
        }  
    }
    void push(char c)  // 字符c入栈
    {
        Node *p = new Node;
        if (p == NULL)
        {	
            cout << "Stack is overflow.\n";
            exit(-1);
        }
        else
        {	
            sz ++;
            p->content = c;
            p->next = top;	
            top = p;
            return;
        }
    }
    char pop()         // 栈顶元素出栈，返回出栈元素
    {
        char result = 0;
        if (top == NULL) 
        {	cout << "Stack is empty.\n";
            exit(-1);
        }
        else 
        {	
            sz --;
            Node *p = top;
            top = top->next;
            result = p->content;
            delete p;
            return result;
        }
    }
    int size()         // 返回栈的大小（栈内元素数量）
    {
        return sz;
    }
};