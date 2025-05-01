#include"book_system.h"
#include<string>
using namespace std;

Library::Library():amount(0), head(nullptr), tail(nullptr){};

Library::~Library(){
    Book* curr = head;
    while(curr)
    {
        head = curr->getnext();
        delete curr;
        curr = head;
    }
    amount = 0;
    head = nullptr;
    tail = nullptr;
}

void Library::add_book(string book_type, string title, string author, string isbn, float data){
    Book* newbook;
    if(book_type == "EBook")  newbook = new EBook(title, author, isbn, data);
    else if(book_type == "PrintedBook") newbook = new PrintedBook(title, author, isbn, data);
    if(!head) head = newbook;
    else{
        Book* curr = head;
        while(curr->getnext()) curr = curr->getnext();
        curr->setnext(newbook);
    }
    tail = newbook;
    amount++;
}

void Library::show_all_books() const{
    Book* curr = head;
    cout<<"There are "<<amount<<" books in the library"<<endl;
    int i = 0;
    while(curr){
        cout<<"No."<<i<<":"<<endl;
        curr->display_info();
        curr = curr->getnext();
    }
}

void Library::delete_book(){
    if(!head) cout<<"The library is empty."<<endl;
    else{
        Book* debook = head;
        head = head->getnext();
        delete debook;
        amount--;
        if(!head) tail = nullptr;
    }
}

void Library::search_book(string keyword) const{
    Book* curr = head;
    bool found = false;
    cout<<"搜索结果如下："<<endl;

    while(curr){
        if(curr->gettitle().find(keyword) != string::npos || curr->getauthor().find(keyword) != string::npos){
            curr->display_info();
            found = true;
        }
        curr = curr->getnext();
    }

    if(!found){
        cout<<"未找到"<<endl;
    }
}

Book::~Book(){
    title.clear();
    author.clear();
    isbn.clear();
    next = nullptr;
}

EBook::~EBook(){
    file_size = 0;
}

void EBook::display_info() const{
    cout<<"title: "<<title<<endl;
    cout<<"author: "<<author<<endl;
    cout<<"isbn: "<<isbn<<endl;
    cout<<"file size: "<<file_size<<" M"<<endl;
}

void EBook::download() const{

}

PrintedBook::~PrintedBook(){
    weight = 0;
}

void PrintedBook::borrow()const{

}

void PrintedBook::display_info()const{
    cout<<"title: "<<title<<endl;
    cout<<"author: "<<author<<endl;
    cout<<"isbn: "<<isbn<<endl;
    cout<<"weight: "<<weight<<" kg"<<endl;
}

int main(){
    Library* lib = new Library;
    lib->add_book("EBook", "hello,world", "lyh", "123456789", 1.5);
    lib->show_all_books();
    lib->search_book("world");
}