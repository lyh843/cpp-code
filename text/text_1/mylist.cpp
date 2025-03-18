#include "mylist.h"
#include <iostream>

using namespace std;

// 构造函数
MyList::MyList() : head(nullptr), list_size(0) {}

// 析构函数
MyList::~MyList() {
    //析构，但不调用clean（），我们不希望有输出
}

// 获取指定位置的节点
MyList::Node* MyList::getNodeAt(int index) const {
    //TODO
    //如果index不合法:
        //cout<<-1<<endl;
    if(index <= list_size - 1 && index >= 0)
    {
        Node *curr = head;
        for(int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr;
    }
    else
    {
        cout<<-1<<endl;
    }
}

// 插入操作
void MyList::insert(int index, int value) {
    //TODO
    //如果index不合法:
        //cout<<-1<<endl;
    if(index >= 0 && index <= list_size)
    {
        list_size++;
        Node *newnode = new Node(value);
        if(index == 0)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *curr = getNodeAt(index - 1);
            newnode->next = curr->next;
            curr->next = newnode;
        }
    }
    else
    {
        cout<<-1<<endl;
    }
}

// 删除操作
void MyList::remove(int index) {
    //TODO
    //如果index不合法:
        //cout<<-1<<endl;
    if(index <= list_size - 1 && index >= 0)
    {
        list_size--;
        if(index == 0)
        {
            Node *freenode = head;
            head = head->next;
            delete(freenode);
        }
        else
        {
            Node *curr = getNodeAt(index - 1);
            Node *freenode = curr->next;
            curr->next = curr->next->next;
            delete(freenode);
        }
    }
    else
    {
        cout<<-1<<endl;
    }
}

// 获取指定位置的元素
int MyList::get(int index) const {
    //TODO
    //如果index不合法,返回-1
    if(index <= list_size - 1 && index >= 0)
    {
        if(index == 0)
        {
            return head->value;
        }
        else
        {
            Node *curr = getNodeAt(index);
            return curr->value;
        }
    }
    else
    {
        return -1;
    }
}

// 设置指定位置的元素
void MyList::set(int index, int value) {
    //TOOD
    //如果index不合法:
        //cout<<-1<<endl;
    if(index <= list_size - 1 && index >= 0)
    {
        if(index == 0)
        {
            head->value = value;
        }
        else
        {
            Node *curr = getNodeAt(index);
            curr->value = value;
        }
    }
    else
    {
        cout<<-1<<endl;
    }
}

// 获取线性表的大小
int MyList::size() const {
    //TODO
    //空就返回0
    return list_size;
}

// 清空线性表
void MyList::clear() {
    //TODO
    while(list_size)
    {
        list_size--;
        Node *freenode = head;
        head = head->next;
        delete(freenode);
    }
    cout<<"Cleared"<<endl;//不要修改
}

// 查询从 index 开始的前 k 个元素的和
int MyList::sum_from(int index, int k) const {
    //TOOD
    //比如1，2，3，4，5，6 sum（0，2） 就是1+2=3
    //如果操作不合法,返回-1
    if(index <= list_size - 1 && index >= 0 && index + k <= list_size && k >= 0)
    {
        int num = 0;
        Node *curr = getNodeAt(index);
        for(int i = 0; i < k; i++)
        {
            num += curr->value;
            curr = curr->next;
        }
        return num;
    }
    else
    {
        return -1;
    }
}

// 反转链表
void MyList::reverse() {
    //TODO
    //注意指针的操作，我们不希望你只是交换值
    Node *curr = head, *next = nullptr, *prev = nullptr;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void MyList::merge(MyList& other){
    //TODO
    Node *curr = getNodeAt(list_size - 1);
    curr->next = other.head;
    list_size += other.list_size;
}
//可以用这个main函数本地测试！或者修改内容~
//提交时候务必注释哦~
int main()
{
    MyList L;
    L.insert (0, 10);
    L.insert (1, 20);
    L.insert (2, 30);
    cout<<L.get(0)<<endl; 
    cout<<L.get(1)<<endl;
    cout<<L.get(2)<<endl;
    cout<<L.sum_from(1, -1)<<endl;
    L.reverse();
    cout<<L.get(0)<<endl; 
    cout<<L.get(1)<<endl;
    cout<<L.get(2)<<endl;
    L.set (1, 25);
    L.remove(0);
    cout<<L.get(0)<<endl;
    cout<<L.get(1)<<endl;
    cout<<L.size()<<endl;
    L.clear();
    cout<<L.size()<<endl;
    L.remove (1);
    cout<<L.get(1)<<endl;
    cout<<L.sum_from (0, 2)<<endl;
    L.reverse();
    cout<<L.get(0)<<endl;
}
