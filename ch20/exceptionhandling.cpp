#include <iostream>
using namespace std;
// basic example of an exception
double CheckDenominator(double den) {
    if (den == 0) {
        throw runtime_error("Math error: Attempted to divide by zero\n");
    } else
        return den;
}
double Division(double num, double den) {
    return (num / CheckDenominator(den));
}

class InvalidInput {};

void factorial(int& facto, int number) {
    if (number > 99) {
        throw InvalidInput();
    } else {
        facto = 1;
        int n = 1;
        while (++n <= number) {
            facto *= n;
        }
    }
}


int main() {
//    int x = -1;
//
//    cout << "Before try \n";
//    try {
//        cout << "Inside try \n";
//        if (x < 0) {
//            throw x;
//        }
//    }
//    catch (int x) {
//        cout << "Exception Caught \n";
//    }
//
//    cout << "After catch (Will be executed) \n";
//    double numerator, denominator, result;
//    numerator = 12.5;
//    denominator = 0;
//
//    try {
//        result = Division(numerator, denominator);
//        cout << "The quotient is "
//             << result << endl;
//    }
//    catch (runtime_error& error) {
//        cout << "Exception occurred" << endl
//             << error.what();
//    }

    int east, eastfact;
    int west, westfact;

    cout << "Enter east: " << endl;
    cin >> east;

    cout << "Enter west: " << endl;
    cin >> west;

    try {
        factorial (eastfact, east);
        factorial (westfact, west);
    } // end of try block
    catch (InvalidInput) {
        cout << "Invalid input!" << endl;
    }
    catch (...) {
        cout << "You put in a letter, dummy." << endl;
    }
}
