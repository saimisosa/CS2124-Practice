#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1){
        return 1;
    } else {
        return n * factorial(n-1);
    }
}


int fib(int val) {
    if (val < 3) {
        return 1;
    } else {
        return fib(val-2) + fib(val-1);
    }
}

int fun(int n)
{
    if (n > 100) {
        return n - 10;
    }
    return fun(fun(n+11));
}


int main() {
    cout << "Demonstrating the use of recursion with a factorial function->" << endl;
    cout << factorial(5);
    cout << "= = = = = =" << endl;


    cout << "Demonstration fibonacci sequence->" << endl;
    cout << fib(9) << endl;
    cout << "= = = = = =" << endl;

    cout << "Mystery func 1? ->" << endl;
    cout << fun(99) << endl;
    cout << "This is called the McCarthy 91 recursive function.\n"
            "For all integer arguments less than or equal to 100\n"
            "and M(n) = n-10 for all numbers greater than 100, the value\n"
            "that will be outputted is 91. All the results of M(n)\n"
            "after n = 101 increases by 1. Example: " << endl;
    cout << fun(99) << endl;
    cout << fun(100) << endl;
    cout << fun(101) << endl;
    cout << fun(102) << endl;
    cout << fun(103) << endl;

    cout << "= = = = = =" << endl;
    return 0;
}
