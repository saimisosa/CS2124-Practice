#include <iostream>
using namespace std;
class Practice {
private:
    int variable1;
    int variable3;
    int variable4;
    static int variable2;
public:
    Practice(int var) : variable1(var) {variable2++;}
    Practice() {
        variable1 = 1;
        variable3 = 3;
        variable4 = 4;

    }
    virtual ~Practice() {variable2--;}
    static int showStaticMember() {
        return variable2;
    }
    void showMember() { cout << variable1 << endl; }
    void showOther() { cout << variable3 << endl; }
    void showAnother() { cout << variable4 << endl; }

};
int Practice::variable2 = 0;

int main() {
    const int size = 3;
    Practice *random[size];

    for (int i = 0; i < size; ++i) { // incrementing static member
        random[i] = new Practice(i);
        cout << Practice::showStaticMember() << endl;
    }

    for (int j = 0; j < size ; ++j) { // decrementing decrementing static member
        cout << Practice::showStaticMember() << endl;
        delete random[j];
        random[j] = NULL;
    }

    // question 4
    void (Practice::*PPF1)();
    void (Practice::*PPF2)();
    void (Practice::*PPF3)();
    Practice myObj;
    PPF1 = &Practice::showMember;
    cout << "Regular member 1: ";
    (myObj.*PPF1)();
    PPF2 = &Practice::showOther;
    cout << "Regular member 2: ";
    (myObj.*PPF2)();
    PPF3 = &Practice::showAnother;
    cout << "Regular member 3: ";
    (myObj.*PPF3)();
    cout << "Static Member: " << Practice::showStaticMember() << endl;

    //question 5


    return 0;

}
