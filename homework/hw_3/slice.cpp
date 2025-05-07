#include "slice.hpp"
int main() {
    Slice a(0);        // check:1_Slice 0, 0

    a.append(0);       // check:append0,0
                       // check:1_Slice 1, 0
                       // check:=0,2

    a.append(1);       // check:append2,1
    a.append(2);       // check:append2,2
                       // check:1_Slice 3, 0
                       // check:=2,6

    a.append(3);       // check:append6,3
    a.append(4);       // check:append6,4
    a.append(5);       // check:append6,5
    a.append(6);       // check:append6,6
                       // check:1_Slice 7, 0
                       // check:=6,14

    a.append(7);       // check:append14,7
    a.append(8);       // check:append14,8
    a.append(9);       // check:append14,9

    std::cout << a[0] << ' ';  // check:pos = 0
                               // 输出 0

    std::cout << a.len() << '\n';  // check_len: 输出长度（应该是10）

    // 一系列切片操作，从 a 中不断缩小范围
    for (int i = 10; i >= 1; --i) {
        Slice b = a[{1, static_cast<size_t>(i)}];  // check:range:1,i
                                                   // check:2_slice ...
                                                   // check:=14,14
        std::cout << b[0] << ' ';                  // check:pos = 0
        b.len();            // check_len:
    }

    // 再次追加
    a.append(10);  // check:append14,10
    a.append(11);  // check:append14,11
    a.append(12);  // check:append14,12
    a.append(13);  // check:append14,13
    a.append(14);  // check:append14,14

    std::cout << a[0] << '\n';    // check:pos = 0
                                  // 输出 10
    std::cout << a.len() << '\n';// check_len:
                                 // 输出长度（15）

    // 再做几次切片
    for (int i = 5; i >= 1; --i) {
        Slice b = a[{1, static_cast<size_t>(i)}];  // range
        std::cout << b[0] << '\n';                 // 取第一个元素
        std::cout << b.len() << '\n';              // 长度
    }

    std::cout << a.len() << '\n';  // check_len: 最终长度
    std::cout << a.cap() << '\n';  // check_cap: 最终容量
    return 0;
}

