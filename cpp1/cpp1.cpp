#include <iostream>
using namespace std;

int main() {
    char ch;
    int val;
    float dec;

    cout << "Input a character: " <<endl;
    cin >> ch;
    cout << "Input an integer: " <<endl;
    cin >> val;
    cout << "Input a float: " <<endl;
    cin >> dec;

    cout << "The character " << ch << " when cast to an int gives value " << int(ch) << endl;
    cout << "The character " << ch << " when cast to an float gives value " << float(ch) << endl;
    cout << "The integer " << val << " when cast to a char gives value " << char(val) << endl;
    cout << "The integer " << val << " when cast to a float gives value " << float(val) << endl;
    cout << "The float " << dec << " when cast to an int gives value " << int(dec) << endl;
    cout << "The float " << dec << " when cast to a char gives value " << char(dec) << endl;

    return 0;
}
