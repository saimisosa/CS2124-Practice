#include <iostream>
#include <cstdlib>
using namespace std;


class Array {
private:
    int size; // size of array
    int* numPtr; // pointer to number on that array
public:
    Array(int arrSize) : size(arrSize) {
        //cout << "Calling constructor..." << endl;
        numPtr = new int[size];
    }

    void fillArray(){
        for (size_t i = 0; i < size; ++i) {
            numPtr[i] = rand()%100;
        }
    }
    void printArray(){
        for (size_t i = 0; i < size; i++) {
            cout << numPtr[i] << ' ';
        }
        cout << endl;
    }

    // destructor
    ~Array(){
        //cout << "Calling destructor..." << endl;
        delete [] numPtr;
    }

    // copy constructor
    Array(const Array& rhs){
        // copy over size
        size = rhs.size;
        // make new dynamic array
        numPtr = new int[size];
        // copy over elements
        for (size_t i = 0; i < size; i++) {
            numPtr[i] = rhs.numPtr[i];
        }
    }

    // assignment operator
    Array& operator= (const Array& rhs){
        if (this != &rhs){ // self check to make sure you're not passing in itself
            // deallocate old memory
            delete [] numPtr;
            // allocate new space
            numPtr = new int[rhs.size];
            // copy the values
            size = rhs.size; // -> set size of curr obj to other obj's size
            for (int i = 0; i < size ; i++) {
                numPtr[i] = rhs.numPtr[i]; // -> make sure every value is copied over in the dynamically allocated array
            }
        }
        return *this;
    }
};

int main() {
    Array firstArr(10);
    Array secondArr(10);

    firstArr.fillArray();
    cout << "===================================" << endl;
    cout << "CONTENTS OF FIRST ARRAY: " << endl;
    firstArr.printArray();

    cout << "===================================" << endl;
    cout << "Assigning empty second array to the first array..." << endl;
    cout << "===================================" << endl;

    secondArr = firstArr;

    cout << "CONTENTS OF SECOND ARRAY: " << endl;
    secondArr.printArray();
    cout << "===================================" << endl;
    Array thirdArray(10);
    thirdArray.fillArray();
    cout << "CONTENTS OF THIRD ARRAY: " << endl;
    thirdArray.printArray();

    cout << "===================================" << endl;
    cout << "Assigning full second array to the contents of the third array..." << endl;
    cout << "===================================" << endl;

    secondArr = thirdArray;
    cout << "Now the second array contains..." << endl;
    secondArr.printArray();
    cout << "===================================" << endl;

    return 0;
}
