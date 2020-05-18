#include <iostream>
using namespace std;

class TwoVariables{
private:
    int val1 = 0;
    int val2 = 0;
public:
    TwoVariables(int first, int second) : val1(first), val2(second) {}

    int sumVariables(){
        return val1 + val2;
    }
};

int main() {
    int numOne = 0;
    int numTwo = 0;

    cout << "Enter the first number you want to be added. " << endl;
    cin >> numOne;
    cout << "Enter the second number you want to be added. " << endl;
    cin >> numTwo;

    TwoVariables sample = {numOne, numTwo};
    cout << "The result of the addition is: " << sample.sumVariables() << endl;
}
