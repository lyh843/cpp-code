#pragma once
#ifndef STUDENTSORTER_H
#define STUDENTSORTER_H

#include <iostream>
#include <cstring>
using namespace std;

struct Student {
	int no;
	char name[101];
};

// 比较函数：按学号升序排序
bool sortByNoAsc(const Student& s1, const Student& s2);

// 比较函数：按学号降序排序
bool sortByNoDesc(const Student& s1, const Student& s2);

// 比较函数：按姓名字典序升序排序
bool sortByNameAsc(const Student& s1, const Student& s2);

#endif
