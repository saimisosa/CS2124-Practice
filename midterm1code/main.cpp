#include <iostream>
using namespace std;

int main() {
    int x = 6;
    int arr[] = {2,3,5,7,11,13,17,19};
    int* p = arr + 1;
    int* q = p + x;
    cout << "A: " << *q << endl;
    *p = x;
    p++;
    cout << "B: " << *p << endl;
}