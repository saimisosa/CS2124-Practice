#include <iostream>
using namespace std;
class Mother {
public:
    void display(){
        cout << "Mother's display method..." << endl;
    }
};
class Daughter : public Mother {
public:
    void display(){
        cout << "Daughter's display method..." << endl;
    }
};
int main() {
    Daughter priya;
    priya.display();
    return 0;
}
