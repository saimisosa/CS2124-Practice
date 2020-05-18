#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    string name;
    double mark1, mark2;
public:
    Student(string fname, double grade1, double grade2) : name(fname), mark1(grade1), mark2(grade2){}

    double calc_media(){
        return ((mark1 + mark2)/2);
    }

    void display(){
        cout << "Name: " << name << "\nMedian Grade: " << calc_media() << endl;
    }

};

int main() {
    string name;
    double grade1;
    double grade2;

    cout << "What is your name? " << endl;
    cin >> name;

    cout << "Enter grade 1: " << endl;
    cin >> grade1;

    cout << "Enter grade 2: " << endl;
    cin >> grade2;

    Student student1 = {name, grade1, grade2};
    student1.display();

}
