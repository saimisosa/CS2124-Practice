//
// Created by Saimanasa Juluru on 1/9/20.
//

#ifndef BANKACCOUNT_HELLO_H
#define BANKACCOUNT_HELLO_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
class BankAccount;
static int managerPin = 34820;
static int curr_acc_nums = 1001;
static std::vector<BankAccount> acc_objs;
class BankAccount {
    private:
        bool isOpen = true;
        std::string balance;
        int accountNum = 0;
        int userPin = 0;
    public:
        // constructors
        BankAccount(int acc_num, int pinNumber, std::string deposit);
        // getters - marked as const
        int getAccountNumber() const;
        double getBalance() const;
        void bankInquiry() const;
        // mutators
        void setPin(int pinNum);
        bool isCorrectPin(int pinNumber);
        void makeDeposit(int pinNumber, std::string deposit);
        void makeWithdrawal(int pinNumber, std::string withdrawal);
        bool closeAccount(int pinNumber);
};
    // out of the class functions
    bool openAccount(int pinNumber, const std::string& deposit);
    void applyInterest(int managerPin, int percent);
    void printAll(int manPin);
    void closeAll(int managerPin);
    BankAccount findBankAccount(int accountNumber);

#endif //BANKACCOUNT_HELLO_H
