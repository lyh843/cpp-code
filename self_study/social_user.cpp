#include "social_user_2.hpp"
#include <string>

int main() {
    PlatformManager manager;

    int choice;
    std::string username;

    do {
        std::cout << "\n====== 社交平台模拟系统 ======\n";
        std::cout << "1. 从文件加载用户\n";
        std::cout << "2. 显示所有用户信息\n";
        std::cout << "3. 添加新用户\n";
        std::cout << "4. 保存用户信息到文件\n";
        std::cout << "5. 显示平台统计\n";
        std::cout << "0. 退出系统\n";
        std::cout << "请选择操作（0-5）：";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.loadFromFile();
            break;
        case 2:
            manager.showAllUsers();
            break;
        case 3:
            std::cout << "请输入用户名：";
            std::cin >> username;
            manager.addUser(username);
            break;
        case 4:
            manager.saveToFile();
            break;
        case 5:
            manager.platformSummary();
            break;
        case 0:
            std::cout << "退出系统。\n";
            break;
        default:
            std::cout << "无效选项，请重新选择。\n";
        }
    } while (choice != 0);

    return 0;
}
