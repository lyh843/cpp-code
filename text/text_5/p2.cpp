#include "p2_2.hpp"

int main(){
    Vehicle* C = new Car("My car");
    C->drive(); // 输出Vehicle name + " drive on road"
    
    Vehicle* B = new Boat("My boat");
    B->drive(); // 输出Vehicle name + " drive on river"
    
    AmphibianCar* A = new AmphibianCar("My amphibian car");
    A->driveAsCar(); // 输出Vehicle name + " drive on road as car"
    A->driveAsBoat(); // 输出Vehicle name + " drive on river as boat"
}