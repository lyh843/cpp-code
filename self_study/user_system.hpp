#include<iostream>

class User{
    private:
    std::string _name;
    std::string _password;
    std::string _email;
    public:
    User(std::string name, std::string password, std::string email):_name(name), _password(password), _email(email){};
    bool check_password(const std::string& pwd){
        if(pwd == _password) return true;
        else return false;
    }
    std::string getEmailDomain(){
        int pos = _email.find('@');
        std::string email_domain = _email.substr(pos + 1);
        return email_domain;
    }
    void maskPassword(){
        for(int i = 2; i < _password.size(); i++){
            _password[i] = '*';
        }
        return;
    }
    void printInfo(){
        std::cout<<"user's name:"<<_name<<std::endl;
        std::cout<<"user's email:"<<_email<<std::endl;
        std::cout<<"user's password:"<<_password<<std::endl;
    }

    std::string getUsername(){return _name;};
};