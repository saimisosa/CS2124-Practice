/*
  The STL. Standard Template Library
  Sec
*/

#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

char* find(char* start, char* stop, char target) {
    for (char* p = start; p != stop; ++p) {
        if (*p == target) {
            return p;
        }
    }
    return stop;
}

template <typename T, typename U>
T find(T start, T stop, U target) {
    for (T p = start; p != stop; ++p) {
        if (*p == target) {
            return p;
        }
    }
    return stop;
}

template <typename T, typename U>
T find_if(T start, T stop, U predicate) {
    for (T p = start; p != stop; ++p) {
        if (predicate(*p)) {
            return p;
        }
    }
    return stop;
}
bool isEven(int value) {
    return value % 2 == 0;
}

struct IsMultipleOfThree {
    bool operator() (int value) {
        return value % 3 == 0;
    }
};

class IsMultiple {
public:
    IsMultiple(int divisor) : divisor(divisor) {}

    bool operator() (int value) {
        return value % divisor == 0;
    }
private:
    int divisor;
};

int main() {

    char array[] = "Bjarne Stroustrup";
    int len = 17;
    sort(array, array+len);

    list<char> lc(array, array+len);
    vector<char> vc(lc.begin(), lc.end());

    char* arrayCharFound = find(array, array+len, 'S');
    vector<char>::iterator vectorCharFound = find(vc.begin(), vc.end(), 'S');
    list<char>::iterator listCharFound = find(lc.begin(), lc.end(), 'S');

    vector<int> vi { 15, 99, 2, 4, 5 };

    find_if(vi.begin(), vi.end(), isEven);

    //for (list<char>::iterator iter = lc.begin();...
    //for (auto iter = lc.begin();...

    auto x = 17.1;
    auto c = 'q';

    string s = "abc";

    // functor
    IsMultipleOfThree isDivisibleBy3;
    isDivisibleBy3(27);

    find_if(vi.begin(), vi.end(), isDivisibleBy3);
    find_if(vi.begin(), vi.end(), IsMultipleOfThree() );

    IsMultiple divBy17(17);
    find_if(vi.begin(), vi.end(), divBy17);

    find_if(vi.begin(), vi.end(), IsMultiple(17));

    find_if(vi.begin(), vi.end(), [] (int value) { return value % 17 == 0; });

    // lambda functions / expressions

    [] () -> void { cout << "I'm a lambda\n"; };
    17;

    [] { cout << "I'm a lambda\n"; } ();


    auto myLambda = [] { cout << "I'm a lambda\n"; };
    myLambda();

    [x] { cout << x << endl; } ()

}

