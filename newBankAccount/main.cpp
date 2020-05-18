#include <iostream>
#include <fstream>
using namespace std;
#import "Bank.h"
#import "BankManager.h"
#import "BankAccount.h"


int main() {
    BankManager billy("Billy", "../password.txt");
    cout << "This bank manager's name is " << billy << "!" << endl;

    Bank chase(&billy);
    BankAccount newAcc(1001, 100);
    BankAccount anotherAcc(1002,932);
    chase.addAccount(&newAcc);
    chase.addAccount(&anotherAcc);
    billy.printAccounts();

}
