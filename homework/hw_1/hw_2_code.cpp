#include <iostream>
#include <cstring>
//题目 5
class Account{
public:
    //构造函数，针对用户传入的参数对对象进行赋值
    Account(char* a, char* b, int c);   
    //显示函数，无需对对象的数值进行修改
    void display() const;    
     //存入函数
    void deposit(int in_money);    
    //取出函数
    void take_out(int out_money);   
private:
//账户的数据成员，其中姓名和账号用char*类型指向用户输入的字符串。
    char *name; //储户姓名
    char *account_number;   //账号
    int money;  //存款
};

//题目 6
class Deque{
public:
    Deque();
    ~Deque();
    void push_front(int x);
    void push_back(int x);
    void pop_front();
    void pop_back();
    size_t size() const;
private:
    struct Node{
        int val;
        struct Node* prev;
        struct Node* next;
        Node(int x);
    };
    Node* head;
    Node* tail;
};

Deque::Deque(){
    head = nullptr;
    tail = nullptr;
}

Deque::Node::Node(int x): val(x), prev(nullptr), next(nullptr){}

Deque::~Deque(){
    while(head)
    {
        Node *denode = head;
        head = head->next;
        delete denode;
    }
    tail = nullptr;
}

void Deque::push_front(int x){
    Node* newnode = new Node(x);
    if(head)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else
    {
        head = newnode;
        tail = newnode;
    }
}

void Deque::push_back(int x){
    Node* newnode = new Node(x);
    if(tail)
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
    else
    {
        head = newnode;
        tail = newnode;
    }
}

void Deque::pop_front(){
    if(head)
    {
        Node* denode = head;
        if(head == tail) tail = nullptr;
        head = head->next;
        if(head) head->prev = nullptr;
        delete denode;
    }
}

void Deque::pop_back(){
    if(tail)
    {
        Node* denode = tail;
        if(tail == head) head = nullptr;
        tail = tail->prev;
        if(tail) tail->next = nullptr;
        delete denode;
    }
}

size_t Deque::size()const{
    Node* curr = head;
    int size = 0;
    while(curr)
    {
        size++;
        curr = curr->next;
    }
    return size;
}


//题目 7
using namespace std;
class Book{
    static int BookCnt;
    char *name;
    public:
        Book(const char * _name);
        ~Book();
        char * get_name() const;
        //void set_name(const char * _name) const;
        //该函数会对对象的数据进行修改，不应该后缀const
        void set_name(const char * _name);
        //对象的数据成员中含有指针，应该添加深拷贝函数
        Book(const Book& other);
};

//对BookCnt进行初始化
int Book::BookCnt = 0;

Book::Book(const char * _name){
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    BookCnt++;
}

//增加深拷贝构造函数
Book::Book(const Book& other){
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    BookCnt++;
}

Book::~Book(){
    delete []name;
    name = nullptr;
    //如果确保析构后不会再次调用已被析构的对象，此处应该赠添BookCnt--
    BookCnt--;
}

char* Book::get_name() const{
    return name;
}

//void Book::set_name(const char* _name) const{
//该函数会对对象的数据进行修改，不应该后缀const
void Book::set_name(const char* _name){
    delete []name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

int main(){
    Book b1("Computer Science");
    //此处会进行拷贝，对象的数据成员中存在指针，应该使用深拷贝
    Book b2(b1);
    return 0;
}