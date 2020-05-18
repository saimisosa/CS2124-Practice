#include <iostream>
using namespace std;
// number 1 - create a destructor for the foo class

class Foo {
public:
    Foo() { cout << "Foo constructor 1 called" << endl; }
    ~Foo() { cout << "Foo destructor 1 called" << endl; }
};

// question 3
class newArray {
public:
    int* data;
    int size;
    newArray(int sizeOf) {
        data = new int[sizeOf];
        size = sizeOf;
    }
    newArray(newArray& rhs) {
        data = new int[rhs.size];
        size = rhs.size;
        for (int i = 0; i < size ; ++i) {
            data[i] = rhs.data[i];
        }
    }
    ~newArray(){
        delete [] data;
    }
};

int main() {
    Foo foo_1;

    // question 2
    int size;
    int input;
    cout << "How many items do you want in this array? ";
    cin >> size;
    int* practiceArray = new int[size];
    cout << "Enter " << size << " items: ";
    for (int i = 0 ; i < size ; i++){
        cin >> input;
        practiceArray[i] = input;
    }
    cout << "Items in this array: ";
    for (int j = 0 ; j < size ; j++){
        cout << practiceArray[j] << " ";
    }
    cout << endl;
    delete[] practiceArray;

    // question 3 driver code
    newArray a(2);//This call the constructor
    a.data[0] = 4; a.data[1] = 2;
    if (true) {
        newArray b = a;
    }
    cout << a.data[0] << endl; // The result is 4
    return 0;
};
