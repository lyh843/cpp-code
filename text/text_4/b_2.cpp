#include<iostream>
#include<string>
using namespace std;

int main(void){
    string a = "helloworld";
    cout<<a.size()<<endl;
    string b = a.substr(2, a.size() - 3);
    cout<<b<<endl;
}