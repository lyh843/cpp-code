#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

class User{
protected:
    std::string _username;
    enum class UserType {None, Normal, VIP} _usertype;
    std::vector<std::string> _friends;

public:
    User(std::string name, UserType type){}
    virtual ~User(){}

    std::string getUserType(){}

    virtual void displayInfo() const = 0;
    virtual void saveInfo() const = 0;
}