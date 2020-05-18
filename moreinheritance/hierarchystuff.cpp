#include <iostream>
using namespace std;

class A {
public:
    A () {
        cout << "Hey! I'm the class A constructor!" << endl;
    }
};

class B {
public:
    B () {
        cout << "Hey! I'm the class B constructor!" << endl;
    }
};

class C : public A {
public:
    B classB;
};

class D {
public:
    D() {
        cout << "D Construtor called..." << endl;
    }
    ~D() {
        cout << "D Destructor called..." << endl;
    }
};

class E : public D {
public:
    E() {
        cout << "E Constructor called..." << endl;
    }
    ~E() {
        cout << "E Destructor called..." << endl;
    }
};
class F : public E {
public:
    F() {
        cout << "F Constructor called..." << endl;
    }
    ~F() {
        cout << "F Destructor called..." << endl;
    }
};

int main() {
    C classC;
    F classF;
    return 0;
}
