#include "MonotonicStack.h"

int MonotonicStack::size(){
    //TODO
    return s.size();
}

void MonotonicStack::pop(){
    //TODO
    if(!s.empty())
    {
        s.pop();
    }
}

int MonotonicStack::top(){
    // //TODO
    return s.empty() ? 0 : s.top();
}

int MonotonicStack::push(int element){
    //TODO
    while(!s.empty() && element < s.top())
    {
        s.pop();
    }
    s.push(element);
    return element;
}
int MonotonicStack::function(const int* arr,int n){
    //TODO
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        int value = arr[i];
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[i])
            {
                value -= arr[j];
                break;
            }
        }
        num += value;
    }
    return num;
}

//可以使用这个main函数在本地进行调试，但提交时请把这段内容注释
int main() {
    MonotonicStack* ms=new MonotonicStack;
    ms->push(8);
    ms->push(4);
    ms->push(6);
    ms->push(2);
    ms->push(3);
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->size()<<endl;
    delete ms;
}
