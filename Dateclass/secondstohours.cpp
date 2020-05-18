#include <iostream>
using namespace std;

class Time {
private:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int remainSeconds = 0;
    string extraZero1 = "";
    string extraZero2 = "";
    string extraZero3 = "";
public:
    Time() = default;; // default constructor

    friend ostream& operator<< (ostream& os, Time& rhs){
        if (rhs.hours < 12 ){
             rhs.extraZero1 = "0";
        }
        if (rhs.minutes < 10){
            rhs.extraZero2 = "0";
        }
        if (rhs.remainSeconds < 10) {
            rhs.extraZero3 = "0";
        }
        if (rhs.hours > 24){
            rhs.hours -= 24;
        }
        os << "HH : MM : SS -> " << rhs.extraZero1 << rhs.hours << " : " << rhs.extraZero2 << rhs.minutes << " : " << rhs.extraZero3 << rhs.remainSeconds << endl;
    }

    int getTime(){
        cout << "Enter the time in seconds. " << endl;
        cin >> seconds;
        return seconds;
    }
    void convert(int seconds){
        hours = seconds / 3600;
        minutes = seconds % 3600;
        minutes /= 60;
        remainSeconds = (seconds % 3600) % 60;
    }

    void addTimes(Time& timeOne, Time& timeTwo){
        seconds = timeOne.seconds + timeTwo.seconds;
        convert(seconds);
    }
};

int main() {
    Time timeNow;
    timeNow.convert(timeNow.getTime());
    cout << timeNow << endl;

//    Time timeOne;
//    timeOne.getTime();
//
//    Time timeTwo;
//    timeTwo.getTime();
//
//    Time timeThree;
//    timeThree.addTimes(timeOne, timeTwo);
//    cout << timeThree << endl;

}


