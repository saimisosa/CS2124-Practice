#include <iostream>
using namespace std;
//template <class weightType, class cageType>
//class ZooAnimal {
//private:
//    char *nameOf;
//    cageType cageNumber;
//    int weightDate;
//    weightType weightOf;
//
//public:
//    ZooAnimal(char*, cageType, int, weightType);
//    friend ostream& operator<< (ostream& os, const ZooAnimal& animal){
//        os << animal.getName() << endl;
//        return os;
//    }
//    ~ZooAnimal () { delete [] nameOf; }
//    void getWeight() const { cout << weightOf << endl; }
//    void changeWeight(int pounds) { weightOf = pounds; }
//    int reptWeight () { return weightDate; }
//    virtual char* reptName() { return nameOf; }
//    virtual string getName() const {
//        string name = "";
//        for (int i = 0; i < strlen(nameOf); i++) {
//            if (nameOf[i] != '\0'){
//                char temp = this->nameOf[i];
//                name += temp;
//            }
//        }
//        return name;
//    }
//    // practice declaring these outside of the class
//    operator int () { return cageNumber; }
//    int operator== (int date){ return (this->weightDate == date); }
//    void operator() (int& whichCage){ whichCage = cageNumber; }
//
//    int operator-- (int) {
//        weightOf--;
//        return this->weightOf;
//    }
//    int operator++ (int) {
//        weightOf++;
//        return this->weightOf;
//    }
//};
//template <class weightType, class cageType>
//ZooAnimal<weightType, cageType>::ZooAnimal(char* nameOf, cageType cageNum, int weightDay, weightType weight) {
//    char *name = new char[20];
//    strcpy (name, nameOf);
//    cageNumber = cageNum;
//    weightDate = weightDay;
//    weightOf = weight;
//}
template <class weightType>
class ZooAnimal {
private:
    char *nameOf;
    int cageNumber;
    int weightDate;
    weightType weightOf;

public:
    ZooAnimal(char*, int, int, weightType);
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
template <class weightType>
ZooAnimal<weightType>::ZooAnimal(char* nameOf, int cageNum, int weightDay, weightType weight) {
    char *name = new char[20];
    strcpy (name, nameOf);
    cageNumber = cageNum;
    weightDate = weightDay;
    weightOf = weight;
}
int main() {
    ZooAnimal<int> bozo ("Bozo", 408, 1027, 400);
    return 0;
}
