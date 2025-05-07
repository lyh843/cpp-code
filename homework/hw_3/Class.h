// 请在测评文件的Class.cpp中完成你的实现
#include <iostream>
#include <string>

/* 加入你需要的头文件 */
#include <vector>

using namespace std;

class Class;
struct Function;
struct CallSite;
bool call(CallSite cs);

struct CallSite {
    const Class &base;
    string function_name;
    const Class &arg;
};

class Class {
  private:
    string name;
    const Class *parent;
    /* 你可以使用其他的数据结构来存储成员函数，也可以添加其他成员变量 */
    vector<Function> funcs;

  public:
    Class(const string &name_) {
        name = name_;
        parent = nullptr;
    }
    bool operator==(const Class &c) const { return name == c.name; }
    string get_name() const { return name; };

    /* 需要实现的接口,不可修改 */
    void add_function(const Function &f);
    // 实验保证任何子类的 inherit 操作都会在类构造之后立刻进行，且不会多次调用
    void inherit(const Class &c);
    friend bool call(CallSite cs);

    // 仅供参考，不需要实现的话注释掉即可
    bool is_ancestor(const Class &c) const; 
};

struct Function {
    string name;
    const Class &arg;
    bool operator==(const Function &f_) const {
        return name == f_.name && arg.get_name() == f_.arg.get_name();
    }
    bool operator<(const Function &f_) const {
        return name < f_.name ||
            (name == f_.name && arg.get_name() < f_.arg.get_name());
    }
};
