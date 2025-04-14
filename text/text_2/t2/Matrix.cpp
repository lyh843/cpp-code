#include"Matrix.h"

// 构造函数
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
	// TODO: 根据给定的行数m和列数c动态分配二维数组内存
    data = new int*[r];
    for(int i = 0; i < r; i++)
    {
        data[i] = new int[c];
    }
}

// 析构函数
Matrix::~Matrix() {
	// TODO: 释放 data 所分配的内存
    for(int i = 0; i < rows; i++)
    {
        delete []data[i];
    }
    delete []data;
}

// 矩阵加法
Matrix operator+(const Matrix& a, const Matrix& b) {
	// TODO: 加法运算符重载
    Matrix c = Matrix(a.rows, a.cols);
    for(int i = 0; i < c.rows; i++)
    {
        for(int j = 0; j < c.cols; j++)
        {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

// 矩阵减法
Matrix operator-(const Matrix& a, const Matrix& b) {
	// TODO: 减法运算符重载
    Matrix c = Matrix(a.rows, a.cols);
    for(int i = 0; i < c.rows; i++)
    {
        for(int j = 0; j < c.cols; j++)
        {
            c.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return c;
}

// 矩阵乘法
Matrix operator*(const Matrix& a, const Matrix& b) {
	// TODO: 乘法运算符重载
    Matrix c = Matrix(a.rows, b.cols);
    for(int i = 0; i < c.rows; i++)
    {
        for(int j = 0; j < c.cols; j++)
        {
            for(int k = 0; k < a.cols; k++)
            {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}