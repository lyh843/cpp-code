#include "p1.h"

int main(){
    AmphibianCar* A = new AmphibianCar("My amphibian car");
    A->drive(); // 输出Vehicle name + " drive on road or river"
    A->Car::drive(); // 调用父类同名函数
    A->Boat::drive(); // 同上
}