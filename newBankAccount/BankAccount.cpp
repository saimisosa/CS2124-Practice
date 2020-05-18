//
// Created by Saimanasa Juluru on 1/18/20.
//

#include "BankAccount.h"

BankAccount::BankAccount(int accountNumber, double deposit) {
    this->accountNumber = accountNumber;
    this->balance = deposit;
}

int BankAccount::getAccountNumber() {
    return this->accountNumber;
}

double BankAccount::getBalance() {
    return this->balance;
}

void BankAccount::close() {
    this->isOpen = false;
}