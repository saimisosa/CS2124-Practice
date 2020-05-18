#include <iostream>
using namespace std;

void say_hello(int times){
    for (int i = 0; i < times; i++){
        cout << "Hello!" << endl;
    }
}

int numProduct(int val1, int val2){
    return val1 * val2;
}

int half(int number){
    cout << number << endl;
    if (number > 0){
        number = number/2;
        half(number);
    }
}

int main() {
    cout << "- - PT 1 - -" << endl;
    cout << endl;
    say_hello(3);
    cout << endl;

    cout << "- - PT 2 - -" << endl;
    cout << endl;
    cout << "The product is: " << numProduct(3,4) << endl;
    cout << endl;

    cout << "- - PT 3 - -" << endl;
    cout << endl;
    half(100);
    cout << endl;
    return 0;
}
