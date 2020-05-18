#include <iostream>
#include <cmath>
using namespace std;

class Shape { // abstract class
public:
    Shape() {cout << "Calling Shape constructor..." << endl;} // default constructor
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~Shape() {cout << "Calling the shape destructor..." << endl;}
};

class Circle : public Shape {
protected:
    double radius;
public:
    explicit Circle(double radius) : Shape(), radius(radius) {};

    virtual double area() { return 3.1415926 * radius * radius; }
    virtual double perimeter() { return 2 * 3.1415926 * radius; }
};

class Polygon : public Shape { // abstract class
protected:
    double length, width;
public:
    Polygon();
    Polygon(double length, double width) : length(length), width(width) {
        cout << "Calling the Polygon parameterized constructor..." << endl;
    }
    ~Polygon() { cout << "Calling polygon destructor..." << endl; }
    virtual double area() = 0;
    virtual double perimeter() = 0;
};
//polygon default contructor
Polygon::Polygon() {
    cout << "Calling Polygon default constructor..." << endl;
}

class Triangle : public Polygon { // abtract class as well
public:
    int numofSides = 3;
};

class Rectangle : public Polygon {
protected:
    int numSides = 4;
public:
    Rectangle(double length, double width) : Polygon(length, width) {};
    virtual double area() { return length * width; }
    virtual double perimeter() { return length * numSides; }
};
class EqualTriangle : public Triangle {
private:
    double length;
public:
    explicit EqualTriangle(double length) : length(length) {};
    virtual double area() { return sqrt(3)/4 * length * length; }
    virtual double perimeter(){ return length * numofSides; }
};
class IsoTriangle : public Triangle {
protected:
    double side1;
    double base;
public:
    IsoTriangle(double side1, double base) : side1(side1), base(base){};

    virtual double area(){
        double height = sqrt(side1*side1 - (base/2)*(base/2));
        return (base * height * .5);
    }
    virtual double perimeter(){ return base + side1*2; }
};

int main() {
    // Shape shape; -> this will not work since i declared area as a pure virtual method
    // Polygon poly; -> this won't work either since polygon is abstract
    Rectangle rect{3.5,2.1};
    EqualTriangle tri{5};
    IsoTriangle iso{3,1};
    Circle cir(3.5);
    cout << endl;
    cout << "Rectangle area: " << rect.area() << endl;
    cout << "Rectangle perimeter: " << rect.perimeter() << endl;
    cout << endl;
    cout << "Equal Triangle area: " << tri.area() << endl;
    cout << "Equal Triangle perimeter: " << tri.perimeter() << endl;
    cout << endl;
    cout << "Iso Triangle area: " << iso.area() << endl;
    cout << "Iso Triangle perimeter: " << iso.perimeter() << endl;
    cout << endl;
    cout << "Circle area: " << cir.area() << endl;
    cout << "Circle perimeter: " << cir.perimeter() << endl;
    cout << endl;

    return 0;
}
