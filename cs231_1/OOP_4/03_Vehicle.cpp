#include<iostream>
using namespace std;

class Car{
public:
    static int number;
    int price;
    void getprice(int);
    void display();
    Car(){
        number++;
    }
};

inline void Car::getprice(int a){
    price = a;
}
int Car::number = 0;
void Car::display(){
    cout<<"Price of car: "<<price<<endl;
    cout<<"No. of cars in showroom: "<<number<<endl;
}

class Bike{
public:
    static int number;
    int price;
    void getprice(int);
    void display();
    Bike(){
        number++;
    }
};

inline void Bike::getprice(int a){
    price = a;
}
int Bike::number = 0;
void Bike::display(){
    cout<<"Price of car: "<<price<<endl;
    cout<<"No. of cars in showroom: "<<number<<endl;
}

int main(){
    Car A1,A2,A3,A4;
    Bike B1,B2,B3;
    A1.getprice(10000);
    B2.getprice(2000);
    A1.display();
    B2.display();
}