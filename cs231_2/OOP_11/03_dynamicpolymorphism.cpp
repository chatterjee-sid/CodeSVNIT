#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
    virtual void printInfo() = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() override {
        return 3.14 * radius * radius;
    }
    void printInfo() override {
        cout << "Circle: Area = " << getArea() << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() override {
        return width * height;
    }
    void printInfo() override {
        cout << "Rectangle: Area = " << getArea() << endl;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() override {
        return 0.5 * base * height;
    }
    void printInfo() override {
        cout << "Triangle: Area = " << getArea() << endl;
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 7.0));
    for (Shape* shape : shapes) {
        shape->printInfo();
    }
    for (Shape* shape : shapes) {
        delete shape;
    }
    return 0;
}