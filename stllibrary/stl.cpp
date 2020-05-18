#include <iostream>
#include <vector>
using namespace std;

template <class T>
void printVector(vector<vector<T>> const &mat) {
    for (vector<T> row: mat) {
        for (T val: row) {
            cout << val << " ";
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> v(3);
    for (int i = 0; i < 3; ++i) {
        v[i].resize(3);
        v[i].push_back(0);
    }
    printVector(v);
    cout <<"Size of 2D vector: " <<  v.size() << endl;

    // a better way of declaring a 3D vector
//    vector<vector<vector<int>>> bigVec(2);
//
//    // assigning every value in the cube to 0
//    for (int j = 0; j < 2 ; ++j) {
//        for (int k = 0; k < 2 ; ++k) {
//            bigVec[j][k].resize(2);
//            bigVec[j][k].push_back(0);
//        }
//    }
//    cout <<"Size of 3D vector: " <<  bigVec.size() << endl;
//    cout << "Printing out this vector would be a mess but the concept is pretty self explanatory..." << endl;
    return 0;
}

