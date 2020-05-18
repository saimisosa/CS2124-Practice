#include <iostream>
#include <string>
using namespace std;

//Make a template out of the prototype
template <typename T>
T myMax(T one, T two);

int main() {
    int i_one = 3, i_two = 5;

    cout << "The max of " << i_one << " and " << i_two << " is "
         << myMax(i_one, i_two) << endl;
    //Test your template on float and string types
    string apple = "donkey", pear = "apple";
    cout << "The max of " << apple << " and " << pear << " is "
         << myMax(apple, pear) << endl;

    double hi = 3.4, hello = 5.6;
    cout << "The max of " << hi << " and " << hello << " is "
         << myMax(hi, hello) << endl;

    return 0;
}


//Make a template out of this function. Don't forget the return type.
template <typename T>
T myMax(T one, T two) {
    T biggest;
    if (one < two) {
        biggest = two;
    } else {
        biggest = one;
    }
    return biggest;
}
