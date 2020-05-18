//
// Created by Saimanasa Juluru on 1/18/20.
//

#ifndef NEWBANKACCOUNT_BANK_H
#define NEWBANKACCOUNT_BANK_H

#import "BankManager.h"
#import "BankAccount.h"

class Bank {
private:
    bool isOpen;
    BankManager* owner;
    BankAccount* accounts[100];
public:
    Bank(BankManager* owner);
    BankAccount* findBankAccount(int accountNum);
    void printAllAccounts();
    void closeAllAccounts();
    void openBank();
    void closeBank();
    void addAccount(BankAccount* toAdd);
    int amtOfAccounts();
};


#endif //NEWBANKACCOUNT_BANK_H
