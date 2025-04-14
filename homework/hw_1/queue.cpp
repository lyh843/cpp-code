#include "queue.h"

// 示例中 Node 的构造函数
Queue::Node::Node(int x) : val(x), next(nullptr) {}

// TODO: 实现 Queue 的构造函数
Queue::Queue() 
{
    head = nullptr;
    tail = nullptr;
}

// TODO: 实现 Queue 的析构函数
Queue::~Queue() 
{
    Node *denode = head;
    while(denode)
    {
        head = head->next;
        delete denode;
        denode = head;
    }
    head = nullptr;
    tail = nullptr;
}

// TODO: 实现 push 操作
void Queue::push(int x) 
{
    Node *node = new Node(x);
    if(!tail)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

// TODO: 实现 pop 操作
void Queue::pop() 
{
    if(!tail)
    {
        std::cout<<"ERR_CANNOT_POP"<<std::endl;
    }
    else
    {
        Node *denode = head;
        if(head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete denode;
    }
}

// TODO: 实现 query 操作
void Queue::query() const 
{
    if(!tail)
    {
        std::cout<<"ERR_CANNOT_QUERY"<<std::endl;
    }
    else
    {
        std::cout<<head->val<<std::endl;
    }
}

// TODO: 实现 size 操作
void Queue::size() const 
{
    int count = 0;
    Node *curr = head;
    while(curr)
    {
        count++;
        curr = curr->next;
    }   
    std::cout<<count<<std::endl;
}

//可以使用这个main函数在本地进行调试，但提交时请把这段内容注释
int main() {
	int T, m;
	std::cin >> T;
	while (T--) {
		Queue q;
		std::cin >> m;
		while (m--) {
			std::string op;
			std::cin >> op;
			if (op == "push") {
				int x;
				std::cin >> x;
				q.push(x);
			}
			else if (op == "pop") {
				q.pop();
			}
			else if (op == "query") {
				q.query();
			}
			else if (op == "size") {
				q.size();
			}
		}
		std::cout << std::endl;
	}
	return 0;
}