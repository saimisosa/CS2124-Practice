//
// Created by Saimanasa Juluru on 1/18/20.
//

#ifndef NEWBANKACCOUNT_BANKACCOUNT_H
#define NEWBANKACCOUNT_BANKACCOUNT_H


class BankAccount {
private:
    bool isOpen = true;
    int accountNumber;
    double balance;
public:
    BankAccount(int accountNumber, double deposit);
    int getAccountNumber();
    double getBalance();
    void close();

};


#endif //NEWBANKACCOUNT_BANKACCOUNT_H
