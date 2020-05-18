#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>
using namespace std;

auto printList(list<int> someList) {
    list<int>::const_iterator regLst;
    for (regLst = someList.begin(); regLst != someList.end(); ++regLst) {
        cout << *regLst << " ";
    }
    cout << endl;
}

auto printBackwards(list<int> someList) {
    someList.reverse();
    printList(someList);
}

const bool isEven(const int i){
    return !(i % 2);
}

class isEven1{
public:
    bool operator() (int i) const {
        return !(i % 2);
    }
};

int main() {
    vector<double> practiceVec;
    for (int i = 0; i < 20; ++i) {
        practiceVec.push_back(i*i);
    }
    cout << "iterators on vectors practice..." << endl;
    if (!practiceVec.empty()) {
        vector<double>::iterator vecLoc;
        for (vecLoc = practiceVec.begin(); vecLoc != practiceVec.end(); ++vecLoc) {
            cout << *vecLoc << " ";
        }
    }
    cout << endl;
    vector<int> testVec;
    testVec = {4,5,1,10,3,9,2};

    list<int> newList(testVec.begin(), testVec.end()); // copies over the items in testVec to a list
    cout << endl;
    cout << "copy vector items to c++ list, use range-for to print out items..." << endl;
    for (int val : newList){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Using the sort methods and printing out the list with iterators..." << endl;
    newList.sort();
    printList(newList);

    cout << endl;
    cout << "Printing every other number in the list using iterators." << endl;

    for (auto listPtr = newList.begin(); listPtr != newList.end(); ++listPtr){
        cout << *listPtr << " ";
        if (++listPtr == newList.end()){
            break;
        }
    }
    cout << endl;
    cout << endl;

    cout << "Print the list backwards...." << endl;
    printBackwards(newList);


    vector<int> checkingOne;
    checkingOne = {1,2,4,5,16,11};

    vector<int>::iterator even;
    cout << endl;
    even = find_if(checkingOne.begin(), checkingOne.end(), isEven); // using the function
    if (*even != 0) {
        cout << "The first even value is " << *even << '\n';
    }
    else {
        cout << "No even values found in the vector." << '\n';
    }

    vector<int> checkingTwo;
    checkingTwo = {10,4,5,11,45,72};

    vector<int>::iterator even1;

    even1 = find_if(checkingTwo.begin(), checkingTwo.end(), isEven1()); // using the class
    if (*even1 != 0) {
        cout << "The first even value is " << *even1 << '\n';
    }
    else {
        cout << "No even values found in the vector." << '\n';
    }



    return 0;
}
