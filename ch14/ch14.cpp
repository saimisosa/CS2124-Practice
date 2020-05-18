#include <iostream>
using namespace std;

// exercise 1
class Rocket {};
class Airplane {};
class JetPlane : public Rocket, Airplane {};

// exercise 2
class Seven47 : public JetPlane {};

// exercise 3
//class Vehicle {
//public:
//    virtual void setWheels() = 0;
//    virtual string getModel() = 0;
//};
//class Car : public Vehicle {
//public:
//    virtual void setWheels();
//    virtual string getModel();
//};
//class Bus : public Vehicle {
//public:
//    virtual void setWheels();
//    virtual string getModel();
//};
// exercise 3 only has vehicle be abstract
// exercise 4 has vehicle and car be abstract, deriving coupe and sports car
class Vehicle { // abstract since at least one method is pure virtual
public:
    virtual void setWheels() = 0;
    virtual string getModel() = 0;
};
class Car : public Vehicle { // abstract since only one function was overridden
public:
    virtual void setWheels();
};
class Coupe : public Car {
public:
    virtual void setWheels();
    virtual string getModel();
};
class SportsCar : public Car {
public:
    virtual void setWheels();
    virtual string getModel();
};
class Bus : public Vehicle {
public:
    void setWheels();
    string getModel();
private:
    int wheels;
    string model;
};
int main() {
    return 0;
}
