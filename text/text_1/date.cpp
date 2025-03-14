#include "date.h"
#include <iostream>
using namespace std;

// 构造函数
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
    if (!isValidDate()) {
        //不需修改，我们希望看到某些异常日期测试用例对应的“-1”输出
    }
}

// 判断日期是否合法
bool Date::isValidDate() const {
    //TODO
    //这个函数需要被其他函数使用
    //未到日期也属于正常输入
    if(this->year >= 0)
    {
        if(this->month >= 1 && this->month <=12)
        {
            if(this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
            {
                if(this->day >= 1 && this->day <=31)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if(this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
            {
                if(this->day >= 1 && this->day <= 30)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else //this->month == 2
            {
                if(isLeapYear(this->year))
                {
                    if(this->day >= 1 && this->day <= 29)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(this->day >= 1 && this->day <= 28) return true;
                    else return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// 判断是否是闰年
bool Date::isLeapYear(int y) const {
    //TODO
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 返回该月的天数
int Date::daysInMonth(int m, int y) const {
    //TODO
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
    else if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else if(m == 2)
    {
        if(isLeapYear(y)) return 29;
        else return 28;
    }
    else return 0;
    //错误返回0
}

// 计算从公元1年1月1日到当前日期的天数
int Date::daysSinceEpoch() const {
    int totalDays = 0;
    // TODO: 计算当前年份中到当前日期的天数
    if(this->isValidDate())
    {
        for(int i = 1; i < year; i++)
        {
            for(int j = 1; j <= 12; j++)
            {
                totalDays += this->daysInMonth(j, i);
            }
        }
        for(int i = 1; i < month; i++)
        {
            totalDays += this->daysInMonth(i, year);
        }
        totalDays += day - 1;
    }   
    else 
    {
        return -1;
    }
    return totalDays;
    //如果非法，返回-1
}

// 计算从某个日期到另一个日期的天数差
int Date::calculateDaysBetween(const Date &other) const {
    //TODO
    if(this->isValidDate() && other.isValidDate())
    {
        int day1 = this->daysSinceEpoch();
        int day2 = other.daysSinceEpoch();
        return (day2 > day1) ? (day2 - day1) : (day1 - day2);
    }
    else
    {
        return -1;
    }
    //如果任意一个日期非法，返回-1
}

// 显示日期
void Date::display() const {
    //TODO：按照yyyy-mm-dd格式输出,加一个换行
    //
    //如：cout<<2025-02-17<<endl;
    if(this->isValidDate())
    {
        if(this->year < 10)
        {
            cout<<"000"<<year<<"-";
        }
        else if(this->year < 100)
        {
            cout<<"00"<<year<<"-";
        }
        else if(this->year < 1000)
        {
            cout<<"0"<<year<<"-";
        }
        else
        {
            cout<<year<<"-";
        }
        if(this->month < 10)
        {
            cout<<"0"<<month<<"-";
        }
        else
        {
            cout<<month<<"-";
        }
        if(this->day < 10)
        {
            cout<<"0"<<day<<endl;
        }
        else
        {
            cout<<day<<endl;
        }
    }
    else
    {
        cout<<-1<<endl;
    }
    //如果非法，输出-1
}
