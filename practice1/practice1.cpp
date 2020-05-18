//Simple grading program

#include <iostream>
using namespace std;
int main() {
    int grade = 0;
    cout << "What was the score you received (0-100)?  " << endl;
    cin >> grade;
    if (grade < 0){
        cout << "You have inputted an invalid number." << endl;
        return 0;
    }
    if (grade >= 90){
        cout << "You have received an A!" << endl;
    }
    else if (grade >= 80 && grade <= 89){
        cout << "You have received a B!" << endl;
    }
    else if (grade >= 70 && grade <= 79){
        cout << "You have received a C!" << endl;
    }
    else if (grade >= 60 && grade <= 69){
        cout << "You have received a D!" << endl;
    }
    else {
        cout << "You have received a F... Better luck next time!" << endl;
    }
}
