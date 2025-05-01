#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

class User {
public:
    enum class UserType { normal, vip };
    User(std::string username, UserType type = UserType::normal)
        : _username(username), _usertype(type) {}
    virtual ~User() {}
    void addFriend(const std::string& friendName) {
        _friends.push_back(friendName);
    }
    void removeFriend(const std::string& friendName) {
        auto it = std::remove(_friends.begin(), _friends.end(), friendName);
        if (it != _friends.end()) {
            _friends.erase(it, _friends.end());
        }
    }
    virtual void displayInfo() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string savefile() const = 0;
protected:
    std::string _username;
    std::vector<std::string> _friends;
    UserType _usertype;

    void displayFriends() const {
        if (_friends.empty()) {
            std::cout << "User is without friends." << std::endl;
        } else {
            std::cout << "User's friends: ";
            for (const std::string& name : _friends) {
                std::cout << name << " ";
            }
            std::cout << std::endl;
        }
    }

    std::string userTypeToString() const {
        return _usertype == UserType::normal ? "Normal" : "VIP";
    }
};

class NormalUser : public User {
public:
    NormalUser(std::string username)
        : User(username, UserType::normal) {}

    void displayInfo() const override {
        std::cout << "User's name: " << _username << std::endl;
        std::cout << "User's type: " << userTypeToString() << std::endl;
        displayFriends();
    }

    std::string getType() const override {
        return "normal";
    }

    std::string savefile() const override{
        std::string result = "Normal " + _username;
        for(const auto& f : _friends) result += " " + f;
        return result;
    }
};

class VIPUser : public User {
public:
    enum class VIPLevel { None, Gold, Platinum, Diamond };
private:
    VIPLevel _viplevel;

    std::string vipLevelToString() const {
        switch (_viplevel) {
            case VIPLevel::Gold: return "Gold";
            case VIPLevel::Platinum: return "Platinum";
            case VIPLevel::Diamond: return "Diamond";
            default: return "None";
        }
    }

public:
    VIPUser(std::string username, VIPLevel level = VIPLevel::None)
        : User(username, UserType::vip), _viplevel(level) {}

    void displayInfo() const override {
        std::cout << "User's name: " << _username << std::endl;
        std::cout << "User's type: " << vipLevelToString() << " VIP" << std::endl;
        displayFriends();
    }

    std::string getType() const override {
        return "vip";
    }
    
    std::string savefile() const override{
        std::string result = "VIP " + _username + " " + vipLevelToString();
        for(const auto& f : _friends) result += " " + f;
        return result;
    }
};

class PlatformManager {
private:
    std::vector<User*> users;
    int sum_vip, sum_normal, sum_all;
public:
    PlatformManager() : sum_vip(0), sum_normal(0), sum_all(0) {}

    void loadFromFile() {
        std::ifstream in_file(".\\file\\social_user.txt", std::ios::in);
        if (!in_file.is_open()) {
        std::cout << "Failed to open input file." << std::endl;
        return;
        }
        users.clear();
        sum_vip = sum_normal = sum_all = 0;
        std::string line;
        while (std::getline(in_file, line)) {
            std::istringstream iss(line);
            std::string type;
            iss >> type;
            if (type == "Normal") {
                std::string username;
                iss >> username;
                User* user = new NormalUser(username);
                std::string friendName;
                while (iss >> friendName) {
                    user->addFriend(friendName);
                }
                users.push_back(user);
                sum_normal++;
            } else if (type == "VIP") {
                std::string username, levelStr;
                iss >> username >> levelStr;
                VIPUser::VIPLevel level = VIPUser::VIPLevel::None;
                if (levelStr == "Gold") level = VIPUser::VIPLevel::Gold;
                else if (levelStr == "Platinum") level = VIPUser::VIPLevel::Platinum;
                else if (levelStr == "Diamond") level = VIPUser::VIPLevel::Diamond;
                User* user = new VIPUser(username, level);
                std::string friendName;
                while (iss >> friendName) {
                    user->addFriend(friendName);
                }
                users.push_back(user);
                sum_vip++;
            }
            sum_all++;
        }
        in_file.close();
        std::cout << "Users loaded from file.\n";
    }

    void saveToFile() {
        std::ofstream out_file(".\\file\\social_user.txt", std::ios::out);
        if (!out_file.is_open()) {
            std::cout << "Failed to open output file." << std::endl;
            return;
        }
        for (User* user : users) {
            out_file << user->savefile()<<std::endl;
        }
        out_file.close();
        std::cout << "Users saved to file.\n";
    }

    void showAllUsers() const {
        for (const User* user : users) {
            user->displayInfo();
            std::cout << "----------------------" << std::endl;
        }
    }

    void addUser(const std::string& username) {
        std::cout << "Please choose the user's type (normal / vip): ";
        std::string usertype;
        std::cin >> usertype;
        User* newuser = nullptr;
        if (usertype == "normal") {
            newuser = new NormalUser(username);
            sum_normal++;
        } else if (usertype == "vip") {
            std::cout << "Please enter vip's level (Gold, Platinum, Diamond): ";
            std::string viplevel;
            std::cin >> viplevel;
            if (viplevel == "Gold")
                newuser = new VIPUser(username, VIPUser::VIPLevel::Gold);
            else if (viplevel == "Platinum")
                newuser = new VIPUser(username, VIPUser::VIPLevel::Platinum);
            else if (viplevel == "Diamond")
                newuser = new VIPUser(username, VIPUser::VIPLevel::Diamond);
            else {
                std::cout << "Invalid VIP level input." << std::endl;
                return;
            }
            sum_vip++;
        } else {
            std::cout << "Invalid user type input." << std::endl;
            return;
        }
        users.push_back(newuser);
        sum_all++;
    }

    void platformSummary() const {
        std::cout << "Total VIP users: " << sum_vip << std::endl;
        std::cout << "Total Normal users: " << sum_normal << std::endl;
        std::cout << "Total Users: " << sum_all << std::endl;
    }

    ~PlatformManager() {
        for (User* user : users) {
            delete user;
        }
    }
};