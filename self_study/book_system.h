#include <iostream>
#include <string>
using namespace std;

class Book{
    protected:
    string title;
    string author;
    string isbn;
    Book* next;
    public:
    Book(string a, string b, string c):title(a), author(b),isbn(c), next(nullptr){};
    virtual ~Book(); 
    virtual void display_info() const = 0;
    Book* getnext(){return next;};
    void setnext(Book* a){next = a;};
    string gettitle() const {return title;};
    string getauthor() const {return author;};
};

class EBook: public Book{
    private:
    float file_size;
    public:
    EBook(string a, string b, string c, float d):Book(a, b, c), file_size(d){};
    ~EBook();
    void download() const;
    void display_info() const override;
};

class PrintedBook: public Book{
    private:
    float weight;
    public:
    PrintedBook(string a, string b, string c, float d):Book(a, b, c), weight(d){};
    ~PrintedBook();
    void borrow() const;
    void display_info() const;
};

class Library{
    private:
    int amount;
    Book *head;
    Book *tail;
    public:
    Library();
    ~Library();
    void show_all_books() const;
    void add_book(string a, string b, string c, string d, float e);
    void delete_book();
    void search_book(string keyword) const;
};