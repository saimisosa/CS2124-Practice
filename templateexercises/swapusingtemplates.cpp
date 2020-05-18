#include <iostream>
using namespace std;

//template to swap values by reference
template <typename T>
void swapVals(T &numOne, T &numTwo) {
    T temp;
    temp = numOne;
    numOne = numTwo;
    numTwo = temp;
}

int main() {
    int first = 3;
    int second = 6;
    swapVals(first, second);
    cout << first << " " << second << endl;

    double three = 12.3;
    double four =  3.1;
    swapVals(three, four);
    cout << three << " " << four << endl;

    return 0;
}
