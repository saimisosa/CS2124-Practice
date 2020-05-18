//
// Created by Saimanasa Juluru on 1/18/20.
//


#ifndef NEWBANKACCOUNT_BANKMANAGER_H
#define NEWBANKACCOUNT_BANKMANAGER_H

#import "Bank.h"
#include <iostream>
using namespace std;

class BankManager {
private:
    Bank *ownedBank;
    int overridePin;
    int fileInput;
    string name;
    void setPin(const string &fileName);

public:
    BankManager(const string &pName, const string &fileName);
    friend ostream &operator<<(ostream &os, BankManager const &rhs) {
        return os << rhs.name;
    }
    void setOwnedBank(Bank* bank);
    void openBank();
    void closeBank();
    void printAccounts();
    void closeAccounts();

};


#endif //NEWBANKACCOUNT_BANKMANAGER_H
