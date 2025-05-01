#include <iostream>

// 窗口基类
class Window {
protected:
    int _x, _y, _w, _h;
public:
    void set(int x, int y, int height, int width)
    {
        _x = x;
        _y = y;
        _h = height;
        _w = width;
    }
};

// 派生类，用链表的形式将窗口组织起来
class WindowInScreen: public Window {
    int id;
    WindowInScreen *next;

public:
    WindowInScreen(int id):id(id), next(nullptr) {}

    void display() {
        // TODO
        std::cout<<"(id:"<<id
        <<", x:"<<_x
        <<", y:"<<_y
        <<", w:"<<_w
        <<", h:"<<_h
        <<")"<<std::endl;
    }

    WindowInScreen* getnext(){
        return next;
    }

    void setnext(WindowInScreen* a){
        next = a;
    }

    int getid(){
        return id;
    }

    void small(WindowInScreen* newone){
        if(_h > _w){
            _h = _h / 2;
            newone->set(_x, _y + _h, _h, _w);
        }
        else{
            _w = _w / 2;
            newone->set(_x + _w, _y, _h, _w);
        }
    }

    void bigprev(WindowInScreen* prev){
        if(prev->_y == _y){
            this->set(prev->_x < _x ? prev->_x : _x, prev->_y < _y ? prev->_y : _y, prev->_h, 2 * prev->_w);
        }
        else
        {
            this->set(prev->_x < _x ? prev->_x : _x, prev->_y < _y ? prev->_y : _y, 2 * prev->_h, prev->_w);
        }
    }

    void bignext(WindowInScreen* next){
        if(next->_y == _y){
            this->set(next->_x < _x ? next->_x : _x, next->_y < _y ? next->_y : _y, next->_h, 2 * next->_w);
        }
        else
        {
            this->set(next->_x < _x ? next->_x : _x, next->_y < _y ? next->_y : _y, 2 * next->_h, next->_w);
        }
    }

    void copy(WindowInScreen* a){
        this->set(a->_x, a->_y, a->_h, a->_w);
    }

    // ~WindowInScreen(){
    //     id = 0;
    //     next = nullptr;
    //     this->set(0, 0, 0, 0);
    // }
};

// 屏幕类
class Screen{
    int _w, _h;
    int count;
    WindowInScreen *root;

public:
    Screen(int w = 1920, int h = 1080): _w(w), _h(h), count(0), root(nullptr){}
    ~Screen() {
        // TODO
    }

    void addWindow(int id) {
        // TODO
        count++;
        WindowInScreen* newwindow = new WindowInScreen(id);
        if(!root){
            root = newwindow;
            newwindow->set(0, 0, _h, _w);
            return;
        }
        WindowInScreen* curr = root;
        while(curr->getnext()){
            curr = curr->getnext();
        }
        curr->setnext(newwindow);
        curr->small(newwindow);
    }

    void delWindow(int id) {
        // TODO
        //删除节点为最后一个
        //删除节点为倒数第二个
        //删除的是唯一一个窗口
        if(!root) return;
        WindowInScreen* delone = root;
        while(delone->getid() != id) delone = delone->getnext();
        if(!delone) return;
        WindowInScreen* lastone = delone;
        WindowInScreen* lasttwo = root;
        while(lastone->getnext()) lastone = lastone->getnext();
        while(lasttwo->getnext() && lasttwo->getnext()!= lastone) lasttwo = lasttwo->getnext();
        if(lastone == delone)
        {
            if(lastone == root)
            {
                root = nullptr;
                delete lastone;
                count--;
                return;
            }
            else
            {
                lasttwo->bignext(lastone);
                lasttwo->setnext(nullptr);
                count--;
                return;
            }
        }
        else if(lasttwo == delone)
        {
            WindowInScreen* pprev = root;
            while(pprev->getnext() && pprev->getnext() != delone) pprev = pprev->getnext();
            pprev->setnext(lastone);
            lastone->bigprev(lasttwo);
            count--;
            return;
        }
        lastone->bigprev(lasttwo);
        // if(delone == root)
        // {
            
        // }
        WindowInScreen* curr = delone->getnext();
        WindowInScreen* pprev = root;
        while(pprev->getnext() && pprev->getnext() != delone && pprev != delone) pprev = pprev->getnext();
        if(delone == root)
        {
            root = root->getnext();
        }
        else
        {
            pprev->setnext(curr);
        }
        WindowInScreen* prev = delone;
        WindowInScreen* temp = new WindowInScreen(0);
        temp->copy(delone);
        while(curr && curr != lastone)
        {
            temp->copy(curr);
            curr->copy(prev);
            prev->copy(temp);
            curr = curr->getnext();
        }
        count--;
        return;
    }

    void display() {
        // TODO
        WindowInScreen* curr = root;
        while(curr){
            curr->display();
            curr = curr->getnext();
        }
    }
};