#include <iostream>
#include <string.h>
using namespace std;
// question 1
//class Animal {
//private:
//    string species;
//};
// question 2
class Array {};
class BoundedArray : public Array {};

// question 3
class Set : private Array {};

// question 4
class String {
public:
    String();
    String(const char* const);
    String(const String&);
    ~String();
    char* getString() const {return itsString;}
    friend istream& operator>>(istream& ifs,  String& rhs){
        ifs >> rhs.getString();
        return ifs;
    }
private:
    String(int);
    char* itsString;
    unsigned short itsLength;
};
// question 5
// you cant declare a class a friend in a function, you have to do that in the class itself.

// question 6
class Animal {
private:
    int itsWeight;
    int itsAge;
public:
    int getWeight() const {return itsWeight;}
    int getAge() const {return itsAge;}
    friend void setValue(Animal& theAnimal, int theWeight) {
        theAnimal.itsWeight = theWeight;
    }
    friend void setValue(Animal& theAnimal, int theWeight, int theAge) {
        theAnimal.itsWeight = theWeight;
        theAnimal.itsAge = theAge;
    }
};

// question 7
// they tried to overload the setValue function outside of the class despite it not being a friend

int main() {
    Animal peppy;
    setValue(peppy, 5);
    cout << peppy.getWeight() << endl;
    setValue(peppy,10,4);
    cout << peppy.getWeight() << " " << peppy.getAge() << endl;
    return 0;
}
