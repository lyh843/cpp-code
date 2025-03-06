//拷贝构造函数
#include <iostream>
class CopyExample {
    public:
        int* data;  
    
        // 构造函数
        CopyExample(int val) {
            data = new int(val);
            std::cout << "Constructor called!\n";
        }
    
        // 拷贝构造函数（深拷贝）
        CopyExample(const CopyExample& other) {
            data = new int(*other.data); // 复制数据
            std::cout << "Copy constructor called!\n"<<*data<<std::endl;
        }
    
        ~CopyExample() {
            delete data;
            std::cout << "Destructor called!\n";
        }
};
void testCopy() {
    CopyExample obj1(10);
    CopyExample obj2(20);
    CopyExample obj3 = obj1;  // 触发拷贝构造函数
    CopyExample obj4 = obj2;
    int a = 1; 
    int b = 2;
    std::cout << a + b << std::endl;
    
}
int main(void)
{
    testCopy();
}
