#include <iostream>
using namespace std;

bool isLeapYear(int year){
    if (year < 1752) {
        return false;
    } else {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
}

int main() {
    int month, day, year;
    int daynum;
    cout << "Input month, day, and year in xx xx xxxx format " << endl;
    cin >> month >> day >> year;

    for (int i = 1; i < month; i++) {
        if (i == 2){
            if (isLeapYear(year)) {
                day += 29;
            } else {
                day += 28;
            }
        } else if ((i % 2 == 0 && i < 7) || (i % 2 != 0 && i > 7)) {
            day += 30;
        } else {
            day += 31;
        }
    }
    day += daynum;
    cout << "The day is: " << day <<endl;
    return 0;
}
