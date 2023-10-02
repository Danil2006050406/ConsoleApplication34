#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
class Shape {
public:
    virtual double calculateArea() const = 0; 
    virtual ~Shape() {} 
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double calculateArea() const override {
        return side * side;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return   radius * radius;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Shape* shapes[] = {
        new Square(5.0),
        new Circle(2.0),
        new Triangle(3.0, 4.0)
    };

    for (int i = 0; i < 3; i++) {
        cout << "Площа фігури " << i + 1 << ": " << shapes[i]->calculateArea() << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
