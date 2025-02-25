#include <iostream>
using namespace std;

class Vehicle {
public:
    string color;
    int maxSpeed;
    void displayVehicleDetails() {
        cout<<"Color: " <<color<<endl;
        cout<<"Max Speed: "<< maxSpeed<<endl;
    }
};

class Twowheeler {
public:
    int noOfGears;
    void displayTwowheelerDetails() {
        cout<<"Number of Gears: "<<noOfGears<<endl;
    }
};

class Fourwheeler {
public:
    int noOfDoors;
    void displayFourwheelerDetails() {
        cout<<"Number of Doors: "<<noOfDoors<<endl;
    }
};

class Car : public Vehicle, public Fourwheeler {
public:
    void displayCarDetails() {
        displayVehicleDetails();
        displayFourwheelerDetails();
        cout<<"This is a Car."<<endl;
    }
};

class Scooter : public Vehicle, public Twowheeler {
public:
    void displayScooterDetails() {
        displayVehicleDetails();
        displayTwowheelerDetails();
        cout<<"This is a Scooter."<<endl;
    }
};

int main() {
    Car myCar;
    myCar.color = "Red";
    myCar.maxSpeed = 120;
    myCar.noOfDoors = 4;
    Scooter myScooter;
    myScooter.color = "Blue";
    myScooter.maxSpeed = 80;
    myScooter.noOfGears = 5;
    cout<<"Car Details:"<<endl;
    myCar.displayCarDetails();
    cout<<endl;
    cout<<"Scooter Details:"<<endl;
    myScooter.displayScooterDetails();
    return 0;
}