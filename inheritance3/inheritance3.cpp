#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    void set_value(string nameOf, int ageOf){
        name = nameOf;
        age = ageOf;
    }
};
class Zebra : public Animal {
public:
    void infoMessage(){
        cout << "The zebra named " << name << " is " << age << " year(s) old. The zebra comes from Africa. \n";
    }
};
class Dolphin : public Animal {
public:
    void infoMessage(){
        cout << "The dolphin named " << name << " is " << age << " year(s) old. The dolphin comes from Australia. \n";
    }
};

int main() {
    Zebra alex;
    Dolphin dolly;
    alex.set_value("Alex", 3);
    dolly.set_value("Dolly", 1);
    alex.infoMessage();
    dolly.infoMessage();

    return 0;
}
