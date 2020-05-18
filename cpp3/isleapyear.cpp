#include <iostream>
using namespace std;
//leap year program

void isLeapYear(int year){
    if (year < 1752) {
        cout << "Leap years didn't exist during the year " << year << "." << endl;
    } else {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            cout << year << " is a leap year." << endl;
        } else {
            cout << year << " is not a leap year." << endl;
        }
    }
}

int main() {
    isLeapYear(2000);
    isLeapYear(1800);
    isLeapYear(1904);
    isLeapYear(1996);
    isLeapYear(2020);
    isLeapYear(2014);
}
