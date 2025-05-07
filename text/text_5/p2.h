#include "Vehicle.h"

// Your code here
class Car: public Vehicle{
    public:
    Car(string name):Vehicle(name){};
    void drive() override{
        driveCar();
    };
    virtual void driveCar(){
        string result = name + " drive on road";
        cout<<result<<endl;
    }
};

class Boat: public Vehicle{
    public:
    Boat(string name):Vehicle(name){};
    void drive() override{
        driveBoat();
    };
    virtual void driveBoat(){
        string result = name + " drive on river";
        cout<<result<<endl;
    }
};

class AmphibianCar: public Car, public Boat{
    public:
    AmphibianCar(string name):Car(name), Boat(name){};
    void driveAsCar(){
        string result = Car::name + " drive on road as car";
        cout<<result<<endl;
    }
    void driveAsBoat(){
        string result = Boat::name + " drive on river as boat";
        cout<<result<<endl;
    }
    void driveCar() override{
        driveAsCar();
    }
    void driveBoat() override{
        driveAsBoat();
    }
};