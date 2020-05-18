//
// Created by Saimanasa Juluru on 1/18/20.
//

#include "Bank.h"

Bank::Bank(BankManager *owner) {
    this->owner = owner;
    owner->setOwnedBank(this);
}

void Bank::openBank() {
    this->isOpen = true;
}

void Bank::closeBank() {
    this->isOpen = false;
}

void Bank::printAllAccounts() {
    for (int i = 0; i < 100 ; ++i) {
        while (this->accounts[i] != nullptr) {
            cout << "Account Number: " << accounts[i]->getAccountNumber() << endl;
            cout << "Available balance: " << accounts[i]->getBalance() << endl;
        }
    }
}

void Bank::closeAllAccounts() {
    for (int i = 0; i < 100 ; ++i) {
        while (this->accounts[i] != nullptr){
            accounts[i]->close();
        }
    }
}

BankAccount * Bank::findBankAccount(int accountNum) {
    for (auto & account : this->accounts) {
        if (account->getAccountNumber() == accountNum){
            return account;
        }
    }
}

int Bank::amtOfAccounts() {
    int amount;
    for (auto & account : accounts) {
        if (account != nullptr){
            amount++;
        }
    }
    return amount;
}

void Bank::addAccount(BankAccount *toAdd) {
    this->accounts[amtOfAccounts()] = toAdd;
}