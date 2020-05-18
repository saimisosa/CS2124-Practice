//
// Created by Saimanasa Juluru on 1/9/20.
//
#include "hello.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

    BankAccount::BankAccount(int acc_num, int pinNumber, string deposit) : accountNum(acc_num), userPin(pinNumber), balance(deposit) {};
    // getters - marked as const
    int BankAccount::getAccountNumber() const { return accountNum; }
    double BankAccount::getBalance() const { return stod(balance); }
    void BankAccount::bankInquiry() const {
        if (!isOpen)  {
            cout << "This account is closed." << endl;
            return;
        }
        cout << "Account number: " << accountNum << endl;
        cout << "Balance: " << balance << endl;
    }
    // mutators

    void BankAccount::setPin(int pinNum){ userPin = pinNum; }

    bool BankAccount::isCorrectPin(int pinNumber){
        if (pinNumber == managerPin){
            return true;
        }
        return pinNumber == userPin;
    }

    void BankAccount::makeDeposit(int pinNumber, string deposit) {
        if (!isCorrectPin(pinNumber)){
            cout << "This isn't the correct pin number. Try again." << endl;
            return;
        }
        if (!isOpen) {
            cout << "This account is closed." << endl;
            return;
        }
        if (deposit.find('.') != string::npos && deposit.substr(deposit.find(".") + 1).length() > 2) {
            cout << "You can only input values with 0, 1, or 2 decimal places" << endl;
            return;
        }
        balance = to_string(stod(balance) + stod(deposit));
        cout << "== UPDATED INFORMATION ==" << endl;
        bankInquiry();
    }

    void BankAccount::makeWithdrawal(int pinNumber, string withdrawal){
        if (!isCorrectPin(pinNumber)){
            cout << "This isn't the correct pin number. Try again." << endl;
            return;
        }
        if (!isOpen) {
            cout << "This account is closed." << endl;
            return;
        }
        if (withdrawal.find('.') != string::npos && withdrawal.substr(withdrawal.find(".") + 1).length() > 2) {
            cout << "You can only input values with 0, 1, or 2 decimal places" << endl;
            return;
        }
        if (stod(withdrawal) > stod(balance)){
            cout << "You cannot withdraw more than you have!" << endl;
            return;
        }
        balance = to_string(stod(balance) - stod(withdrawal));
        cout << "== UPDATED INFORMATION ==" << endl;
        bankInquiry();
    }

    bool BankAccount::closeAccount(int pinNumber){
        if (!isCorrectPin(pinNumber)){
            cout << "Wrong pin." << endl;
            return true;
        }
        if (!isOpen){
            cout << "Account is already closed " << endl;
            return true;
        }
        isOpen = false;
        cout << "Account is now closed. Bye!" << endl;
        return true;
    }
    bool openAccount(int pinNumber, const string& deposit){
        if (deposit.find('.') != string::npos && deposit.substr(deposit.find(".") + 1).length() > 2){
            cout << "You can only input values with 0, 1, or 2 decimal places" << endl;
            return false;
        }

        BankAccount new_Account(curr_acc_nums, pinNumber, deposit);
        new_Account.setPin(pinNumber);
        acc_objs.push_back(new_Account);
        cout << "Account created." << endl;
        cout << "Account number: " << new_Account.getAccountNumber() << endl;
        curr_acc_nums++;

        return true;
    }
    void applyInterest(int managerPin, int percent){
        double interestRate = (percent / 100.0);
        for (int i = 0; i < acc_objs.size(); i++){
            double amtToAdd = (acc_objs[i].getBalance() * interestRate);
            ostringstream newstr;
            newstr << fixed;
            newstr << setprecision(2);
            newstr << amtToAdd;
            string newstr1 = newstr.str();
            acc_objs[i].makeDeposit(managerPin, newstr1);
        }
    }
    void printAll(int manPin){
        for (int i = 0; i < acc_objs.size(); i++){
            if (!acc_objs[i].isCorrectPin(manPin)){
                cout << "Hey! That isn't the manager's pin number!" << endl;
                break;
            }
            acc_objs[i].bankInquiry();
        }
    }
    void closeAll(int managerPin){
        for (int i = 0; i < acc_objs.size(); i++){
            acc_objs[i].closeAccount(managerPin);
        }
    }
    BankAccount findBankAccount(int accountNumber){
        for (int i = 0; i < acc_objs.size(); i++){
            if (acc_objs[i].getAccountNumber() == accountNumber){
                return acc_objs[i];
            }
        }
    }

