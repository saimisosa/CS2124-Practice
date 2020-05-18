#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    double speed = 0;
    double weight = 0;
    string size;
public:
    Vehicle(double speed, double weight, string size) : speed(speed), weight(weight), size(size) {
        cout << "I do not have a sound yet!" << endl;
    };
    // getters
    virtual double getSpeed() const { return speed; }
    virtual double getWeight() const { return weight; }
    virtual string getSize () const { return size; }
};

class Car : public Vehicle {
private:
    double speed = 0;
    double weight = 0;
    string size;
    string model;
public:
    Car(double speed, double weight, string size, string model) : Vehicle(speed, weight, size), model(model) {
        cout << "Vroom Vroom!" << endl;
    };

    //new method solely for the car
    string getModel() const { return model; }
};

int main() {
    Vehicle generic(30,100, "small");
    cout<< generic.getWeight() << endl;
    cout << generic.getSize() << endl;
    cout << generic.getSpeed() << endl;
    Car chevy(50, 60, "medium", "chevy");
    cout << chevy.getWeight() << endl;
    cout << chevy.getSize() << endl;
    cout << chevy.getSpeed() << endl;
    cout << chevy.getModel() << endl;

    return 0;
}
