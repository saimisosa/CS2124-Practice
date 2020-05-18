#include <iostream>
#include <string>
using namespace std;

//chapter 12 question 1
// virtual void anInt(int val) {....}
// OR
// virtual void anInt(int);

//chapter 12 question 2
class Shape{};
class Rectangle : public Shape {};
class Square : public Rectangle {};

//chapter 12 question 3
//Square(int length) : Rectangle(length, width){};

//chapter 12 question 4
//class Square{
//public:
//    Square(){};
//    virtual Square* clone() {return new Square(*this);}
//};

int main() {
    // chapter 13 problem 1
    int tictactoe[10][10] = {
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1}
    };
    // chapter 13 problem 2
    for (int i = 0; i < 10 ; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            tictactoe[i][j] = 0;
        }
    }
    for (int i = 0; i < 10 ; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            cout << tictactoe[i][j] << " ";
        }
        cout << endl;
    }
    // chapter 13 problem 3
    char fn[] = "Saimanasa";
    char mn[] = "S.";
    char ln[] = "Juluru";
    char fullName[100];
    int buffer = 0;

    strcpy(fullName, fn);
    buffer = strlen(fn);
    strcpy(fullName + buffer, " ");
    buffer += 1;
    strcpy(fullName + buffer, mn);
    buffer += 2;
    strcpy(fullName + buffer, " ");
    buffer += 1;
    strcpy(fullName + buffer, ln);

    cout << fullName << endl;

    return 0;
}
