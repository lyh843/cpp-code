#include <iostream>

class Matrix{
private:
    int* data;
    int rols, cols;
public:
    Matrix();
    ~Matrix();
    void input();
    void print();
    Matrix& operator+();
    Matrix& operator-();
    Matrix& operator*();
    int& operator[]();
};