#include "Vehicle.h"

// Your code here

class Car: public Vehicle{
    public:
    Car(string name):Vehicle(name){};
    void driveAsCar(){
        string result = Car::name + " drive on road as car";
        cout<<result<<endl;
    }
    void drive() override;
};

class Boat: public Vehicle{
    public:
    Boat(string name):Vehicle(name){};
    void driveAsBoat(){
        string result = Boat::name + " drive on river as boat";
        cout<<result<<endl;
    }
    void drive() override;
};

class AmphibianCar: public Car, public Boat{
    public:
    AmphibianCar(string name):Car(name), Boat(name){};
};

void Car::drive() {
    if(dynamic_cast<AmphibianCar*>(this)){
        driveAsCar();
    }
    else cout<<name <<" drive on road"<<endl;
};

void Boat::drive() {
    if(dynamic_cast<AmphibianCar*>(this)){
        driveAsBoat();
    }
    else cout<<name <<" drive on river"<<endl;
};