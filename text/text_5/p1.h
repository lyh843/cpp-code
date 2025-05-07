#include "Vehicle.h"

// Your code here
class Car: virtual public Vehicle{
    public:
    Car(string name):Vehicle(name){};
    void drive() override{
        string result = name + " drive on road";
        cout<<result<<endl;
    };
};

class Boat: virtual public Vehicle{
    public:
    Boat(string name):Vehicle(name){};
    void drive() override{
        string result = name + " drive on river";
        cout<<result<<endl;
    };
};

class AmphibianCar: public Car, public Boat{
    public:
    AmphibianCar(string name):Car(name), Vehicle(name), Boat(name){};
    void drive() override{
        string result = name + " drive on the road or river";
        cout<<result<<endl;
    }
};