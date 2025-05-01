#include<iostream>
#include<vector>
#include<string>
#include"user_system.hpp"

using namespace std;

int main(){
    vector<User> users;

    // 预设几个用户
    users.emplace_back("alice", "al1234", "alice@gmail.com");
    users.emplace_back("bob", "bobpass", "bob@qq.com");
    users.emplace_back("charlie", "ch@rlie1", "charlie@outlook.com");

    cout << "==== 用户查找系统 ====" << endl;
    cout << "请输入用户名进行查找: ";
    string username;
    getline(cin, username);

    bool found = false;
    for (auto& user : users) {
        if (user.getUsername() == username) {
            found = true;
            cout << "用户信息:\n";
            user.maskPassword();  // 遮罩密码
            user.printInfo();     // 显示信息
            cout << "邮箱域名: " << user.getEmailDomain() << endl;
            break;
        }
    }

    if (!found) {
        cout << "未找到该用户。" << endl;
    }
}