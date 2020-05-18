#include <iostream>
using namespace std;

class Vector {
private:
    size_t theSize;
    size_t theCapacity;
    int* data;
public:
    // constructor
    // this does not handle uninitialized vectors
    // for example, with this contructor, you couldn't do Vector<int> v;
//    Vector(size_t size, int nums) {
//        theSize = size;
//        theCapacity = size;
//        data = new int[size];
//        for (size_t i = 0; i < size; ++i) {
//            data[i] = nums;
//        }
//    }
    Vector() : theSize(0), theCapacity(1), data(new int[1]) {}

    explicit Vector(size_t theSize, int value = 0)
            : theSize(theSize), theCapacity(theSize), data(new int[theSize])
    {
        for (size_t index = 0; index < theSize; ++index) {
            data[index] = value;
        }
    }
    // size method
    size_t size() const {
        return theSize;
    }
    // square brackets operator
    // we need this so we can use indexing on the vector contents itself
    // i.e with a vector names apple...
    // vector[0] should be able to work after we implement this

    // destructor
    ~Vector(){
        delete [] data; // deletes the array itself
    }
    // copy constructor
    Vector(const Vector& rhs){
        // copy over size
        theSize = rhs.theSize;
        // copy over capacity
        theCapacity = rhs.theCapacity;
        // make a new dynamic array
        data = new int[theCapacity];
        // copy over elements
        for (int i = 0; i < theSize; ++i) {
            data[i] = rhs.data[i];
        }
    }
    // assignment operator
    Vector& operator= (const Vector& rhs){
        // self assignment check
        if (this != &rhs){
            // deallocate old memory
            delete [] data;
            // reset the size and capacity
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            // allocate new space
            data = new int[rhs.theCapacity];
            // copy over the values
            for (size_t i = 0; i < theSize; ++i) {
                data[i] = rhs.data[i];
            }
        }
        // return itself
        return *this;
    }
    void push_back(int value){
        // if vector is empty
        if (theCapacity == 0){
            theCapacity++; // increases the capacity
            data = new int[theCapacity]; // makes a new array with that size
        }
        // if there is no more room
        if (theSize == theCapacity) {
            int* lhs = data; // new pointer to the current data in the array
            data = new int[2*theCapacity]; // resizing the original data array to hold more
            theCapacity*=2; // increases the capacity
            for (size_t i = 0; i < theSize; ++i) { // copying everything in the old array to the new one
                data[i] = lhs[i]; // yaaay copying
            }
            delete [] lhs; // deletes the old array
        }
        // outside of these if statements...
        data[theSize] = value; // sets the value you're pushing back to the end of the array
        theSize++; // increases the size
    }
    void pop_back(){
        if (theSize == 0){
            return;
        } else {
            theSize--;
            return;
        }
    }
    void clear(){
        theSize = 0;
    }
    int operator[](const size_t index) const { return data[index]; }
};

int main() {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << v.size() << endl;
    for (int i = 0; i < v.size() ; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.pop_back();
    cout << v.size() << endl;
    for (int i = 0; i < v.size() ; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    Vector a;
    a.pop_back();
    cout << a.size() << endl;
}
