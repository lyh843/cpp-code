// MyQueue.cpp
#include "MyQueue.h"

MyQueue::MyQueue()
{
    // TODO
}

// 元素从队尾入队
void MyQueue::push(char c)
{
    // TODO
    s1.push(c);
}

// 队首元素出队，返回出队的元素（我们没有定义空队列pop操作，测试用例中不会涉及）
char MyQueue::pop()
{
    char result;
    // TODO
    while(s1.size())
    {
        char temp = s1.pop();
        s2.push(temp);
    }
    result = s2.pop();
    while(s2.size())
    {
        char temp = s2.pop();
        s1.push(temp);
    }
    return result;
}

// 返回队列的大小（队列内元素的个数）
int MyQueue::size()
{
    int result;
    // TODO
    result = s1.size();
    return result;
}
