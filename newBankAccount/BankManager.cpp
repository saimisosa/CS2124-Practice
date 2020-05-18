//
// Created by Saimanasa Juluru on 1/18/20.
//

#include "BankManager.h"
#include <fstream>

BankManager::BankManager(const string &pName, const string &fileName) {
    name = pName;
    setPin(fileName);
}

void BankManager::setPin(const string &fileName) {
    ifstream pinNumber;
    pinNumber.open(fileName);
    pinNumber >> fileInput;
    overridePin = fileInput;
    pinNumber.close();
}

void BankManager::setOwnedBank(Bank *bank) {
    this->ownedBank = bank;
}

void BankManager::openBank() {
    this->ownedBank->openBank();
}

void BankManager::closeBank() {
    this->ownedBank->closeBank();
}

void BankManager::closeAccounts() {
    this->ownedBank->closeAllAccounts();
}

void BankManager::printAccounts() {
    this->ownedBank->printAllAccounts();
}