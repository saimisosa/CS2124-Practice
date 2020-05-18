#include <iostream>
using namespace std;
template <class T>
class ZooAnimal {
private:
    char *nameOf;
    int cageNumber;
    int weightDate;
    T weightOf;

public:
    ZooAnimal(char* name = "Nameless", int cageNum = 9999, int dateWeight = 101, T weightNum = 100) { // default parameters
        // INITIALIZATION LIST --> not the typical way but this is essentially what they asked for...
        // name
         nameOf = new char[20];
         strcpy(nameOf, name);
         // cage number
         cageNumber = cageNum;
         // date weighed
         weightDate = dateWeight;
         // the actual weight
         weightOf = weightNum;
    }
    friend ostream& operator<< (ostream& os, const ZooAnimal& animal){
        os << animal.getName() << endl;
        return os;
    }
    ~ZooAnimal () { delete [] nameOf; }
    void getWeight() const { cout << weightOf << endl; }
    void changeWeight(int pounds) { weightOf = pounds; }
    int reptWeight () { return weightDate; }
    virtual char* reptName() { return nameOf; }


    virtual string getName() const {
        string name = "";
        for (int i = 0; i < strlen(nameOf); i++) {
            if (nameOf[i] != '\0'){
                char temp = this->nameOf[i];
                name += temp;
            }
        }
        return name;
    }


    // practice declaring these outside of the class
    operator int () { return cageNumber; }
    int operator== (int date){ return (this->weightDate == date); }
    void operator() (int& whichCage){ whichCage = cageNumber; }

    int operator-- (int) {
        weightOf--;
        return this->weightOf;
    }
    int operator++ (int) {
        weightOf++;
        return this->weightOf;
    }
};
class Mammal {
protected:
    float minimumVolume;
    int minimumWeight;
public:
    Mammal (float minV, int minW) : minimumVolume(minV), minimumWeight(minW) {} // constructor function
    inline ~Mammal () {}; // destructor function
    float reptminimumVolume ();
    int reptminimumWeight ();
};

class LargeAnimal : public ZooAnimal<int>, public Mammal {
private:
    char* species;
    float cageMinimumVolume;
public:
    LargeAnimal (char* name, int cageNum, int weightDate, int weightNum, char* speciesName, int cageVol, float minV, int minW)
    : ZooAnimal(name, cageNum, weightDate, weightNum), Mammal(minV, minW) {
        species = new char[30];
        strcpy(species, speciesName);
        cageMinimumVolume = cageVol;
    };

    ~LargeAnimal () { delete [] species; }
    float reptCageMinimumVolume () {
        if (Mammal::minimumWeight < 500) {
            return cageMinimumVolume;
        } else {
            return reptWeight();
        }
    }
    virtual char* reptName() { return species; }
};

int main() {
    ZooAnimal<int> abby("Abby", 1000, 1230, 30);
    cout << "Cage #:" << int(abby) << endl; // overloading the int operator to return the cage number of the animal
    cout << "Name: ";
    //abby.getName();
    cout << abby; // overloaded ostream operator
    abby.changeWeight(34);
    cout << "Weight: ";
    abby.getWeight();
    if (abby == 1230){ // overloaded ==
        cout << "Yes, that's the weight date." << endl;
    } else {
        cout << "No, that's not the weight date." << endl;
    }
    if (abby == 0101){
        cout << "Yes, that's the weight date." << endl;
    } else {
        cout << "No, that's not the weight date." << endl;
    }
    cout << "------------------" << endl;

    ZooAnimal<int> apple;
    cout << "Cage #: " << int(apple) << endl; // should show the default value set, 9999
    cout << "Weight (before increment): ";
    apple.getWeight();
    apple++; // overloaded ++
    cout << "Weight (after increment): ";
    apple.getWeight();
    cout << "Name: ";
    //apple.getName();
    cout << apple; // ostream operator .
    cout << "------------------" << endl;

    ZooAnimal<int> bozo ("Bozo", 408, 1027, 400);
    int cage;
    bozo(cage); // overloaded () operator
    cout << "Weight date: " << bozo.reptWeight() << endl;
    cout << "Using the overloaded () operator: " << cage << endl;
    cout << "Before decrement ";
    bozo.getWeight();
    bozo--; // overloaded --
    cout << "After decrement: ";
    bozo.getWeight();
    cout << "------------------" << endl;

    ZooAnimal<int> celine;
    LargeAnimal gonzo("Gonzo", 342, 1030, 100, "Tiger", 70, 501.11, 98);
    cout << celine.reptName() << endl;
    cout << gonzo.reptName() << endl;
    cout << gonzo.reptCageMinimumVolume() << endl;

}



