#include <iostream>
#include <string>
using namespace std;

// no copy constructor bc there is no such thing as an "EMPTY" person

class DayMonthYear {
private:
    int day, month, year;
public:
    DayMonthYear(const string& date) { // mm/dd/yyyy format
        month = atoi(date.substr(0,2).c_str());
        day = atoi(date.substr(3,2).c_str());
        year = atoi(date.substr(6,4).c_str());
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setMonth(int monthNum) {
        if (monthNum > 0 && monthNum <= 12)
            month = monthNum;
        else {
            cerr << "Date::setMonth: Invalid month: " << monthNum << endl;
            exit(1);
        }
    }
    void display(ostream& os = cout) const {
        os << month << '/' << day << '/' << year << endl;
    }


};

class Person {
private:
    string firstName;
    string lastName;
    DayMonthYear birthday;
    bool isMarried = false;
    Person* spouse;

public:
    Person(const string& fn, const string& ln, const DayMonthYear& birthday)
            : birthday(birthday), firstName(fn), lastName(ln), spouse(nullptr) {
    }

    void displayPerson(ostream& os = cout) const {
        os << "Name: " << firstName << ' ' << lastName << ", date of birth: ";
        birthday.display(os);
    }

    void marryPerson(Person& bethrothed){
        if (&bethrothed == this){ // if you're trying to marry yourself...
            cout << "You cannot marry yourself!" << endl;
        } else if (this->isMarried) { // if you're already married...
            cout << "Hey! You're already married! Stop that!" << endl;
        } else if (bethrothed.isMarried) { // if the person you're trying to wed is already married...
            cout << "Hey! That person is already married! Stop that!" << endl;
        } else {
            spouse = &bethrothed;
            bethrothed.spouse = this;
            this->isMarried = true;
            bethrothed.isMarried = true;
        }
    }

    void showSpouse() const {
        if (spouse == NULL){ // if you don't have a spouse...
            cout << "This person doesn't have a spouse." << endl;
        } else {
            spouse->displayPerson();
        }
    }
};

int main() {
    cout << "PERSON CREATED" << endl;
    DayMonthYear birthdayOne("03/14/1980");
    Person alfred("Alfred", "Newman", birthdayOne);
    alfred.displayPerson();
    alfred.showSpouse(); // -> will cout that the person doesn't have a spouse
    cout << endl;

    alfred.marryPerson(alfred); // this will not work since the marries method checks if you pass in yourself
    alfred.showSpouse();
    cout << endl;

    cout << "PERSON CREATED" << endl;
    DayMonthYear birthdayTwo("06/01/1980");
    Person monroe("Marilyn", "Monroe", birthdayTwo);
    monroe.displayPerson();
    monroe.showSpouse(); // -> will cout that the person doesn't have a spouse
    cout << endl;

    alfred.marryPerson(monroe); // -> used marry method on alfred with monroe
    cout << "Person Alfred's spouse's info is: " << endl;
    alfred.showSpouse();
    cout << endl;

    cout << "Monroe's spouse's info is: " << endl;
    monroe.showSpouse(); // -> monroe should also show that they are married to alfred despite not using the marries method explicitly
    cout << endl;

    cout << "PERSON CREATED" << endl;
    DayMonthYear birthdayThree("12/12/1980");
    Person roger("Roger", "Lee", birthdayThree);
    roger.displayPerson();
    cout << endl;

    cout << "In which Monroe tries to marry Roger but it doesn't go to plan..." << endl;
    monroe.marryPerson(roger);
    cout << "[Spouse status] ";
    monroe.showSpouse();
    cout << endl;

    cout << "In which Roger tried to marry Monroe but it also doesn't go to plan..." << endl;
    roger.marryPerson(monroe);
    cout << "[Spouse status] ";
    roger.showSpouse();
    cout << endl;


}
