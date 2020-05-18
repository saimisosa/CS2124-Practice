#include <iostream>
using namespace std;

int main() {
    // Number 1
    char c = 'T', d = 'S';
    char *p1 = &c;
    char *p2 = &d;
    char *p3;


    p3 = &d;
    cout << "*p3 = " << *p3 << endl;   // (1)

    p3 = p1;
    cout << "*p3 = " << *p3            // (2)
         << ", p3 = " << p3 << endl;   // (3)

    *p1 = *p2;
    cout << "*p1 = " << *p1            // (4)
         << ", p1 = " << p1 << endl;   // (5)

    // Number 2
    int *p;
    int i;
    int k;
    i = 42;
    k = i;
    p = &i;

    *p = 75;
    cout << i << endl;

    char blocks[3] = {'A','B','C'};
    char *ptr = &blocks[0];
    cout << "a)" << *ptr << endl;
    char temp;

    temp = blocks[0];
    cout << "b)" << temp << endl;
    temp = *(blocks + 2);
    cout << "c)" << temp << endl;
    temp = *(ptr + 1);
    cout << "d)" << temp << endl;
    temp = *ptr;
    cout << "e)" << temp << endl;

    ptr = blocks + 1;
    cout << "f)" << ptr << endl;
    temp = *ptr;
    cout << "g)" << temp << endl;
    temp = *(ptr + 1);
    cout << "h)" << temp << endl;

    ptr = blocks;
    cout << "i)" << ptr << endl;
    temp = *++ptr;
    cout << "j)" << temp << endl;
    temp = ++*ptr;
    cout << "k)" << temp << endl;
    temp = *ptr++;
    cout << "l)" << temp << endl;
    temp = *ptr;
    cout << "m)" << temp << endl;

    return 0;

}
