//Saimanasa Juluru
//CS 2124
//14 February 2020
//Rec 03
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Question 1
struct Account1 {
    string accountName;
    int accountNumber;
};
//Question 2
class Account {
    //c
    friend ostream& operator<<(ostream& os, const Account& anAccount);
public:
    Account(const string& aName, int aNum) : accountName(aName), accountNumber(aNum) {}
    const string& getName() { return accountName; }
    const int getNumber() { return accountNumber; }

    void deposit(int amount) {
        balance += amount;

        Transaction newAction("Deposit", amount);
        transactionHistory.push_back(newAction);
    }
    void withdraw(int amount) {
        if (balance - amount < 0) {
            cerr << "Not enough money to withdraw $" << amount << " from " << accountName << endl;
        }
        else {
            balance -= amount;
            transactionHistory.emplace_back("Withdraw", amount);
        }
    }


private:
    //Question 3 + 4 making transation private)
    class Transaction {
        friend ostream& operator<<(ostream& os, const Transaction& aTransaction) {
            os << aTransaction.transactionType << " of amount $" << aTransaction.transactionAmount << endl;
            return os;
        }
    public:
        Transaction(const string& type, int amount) : transactionType(type), transactionAmount(amount) {}
    private:
        string transactionType;
        int transactionAmount;
    };

    string accountName;
    int accountNumber;
    int balance;
    vector<Transaction> transactionHistory;
};

//2b + Question 3 (Transation History)
ostream& operator<<(ostream& os, const Account& anAccount) {
    os << "Account: " << anAccount.accountName << " #"
       << anAccount.accountNumber << " Balance: " << anAccount.balance
       << " Transaction history: " << endl;
    for (size_t transaction = 0; transaction < anAccount.transactionHistory.size(); ++transaction) {
        os << anAccount.transactionHistory[transaction];
    }
    return os;
}

void localInstance(ifstream& accountFile, vector<Account>& accounts);
void curlyBrace(ifstream& accountFile, vector<Account>& accounts);
void tempInstance(ifstream& accountFile, vector<Account>& accounts);
void emplaceBack(ifstream& accountFile, vector<Account>& accounts);
void readTransaction(ifstream& transationFile, vector<Account>& accounts);
void displayAccounts(const vector<Account>& accounts);

int main() {
    ifstream accountFile("accounts.txt");
    if (!accountFile) {
        cerr << "File couldn't be opened\n";
    }

    vector<Account> accounts;

    emplaceBack(accountFile, accounts);

    displayAccounts(accounts);
    accountFile.close();

    ifstream transationFile("transactions.txt");
    readTransaction(transationFile, accounts);
    displayAccounts(accounts);
    transationFile.close();
}


//Defining local instances of account, assign values to struct, and push back object
void localInstance(ifstream& accountFile, vector<Account>& accounts) {
    string name;
    int num;
    Account1 anAccount;
    while (accountFile >> name >> num) {
        anAccount.accountName = name;
        anAccount.accountNumber = num;
    }
}

//Use curly braces initilalizers to initialize instance
void curlyBrace(ifstream& accountFile, vector<Account>& accounts) {
    string name;
    int num;
    while (accountFile >> name >> num) {
        Account anAccount{ name, num };
        accounts.push_back(anAccount);
    }
}

//pass temporary instances
void tempInstance(ifstream& accountFile, vector<Account>& accounts) {
    string name;
    int num;
    while (accountFile >> name >> num) {
        accounts.push_back(Account(name, num));
    }
}

//using emplace_back
void emplaceBack(ifstream& accountFile, vector<Account>& accounts) {
    string name;
    int num;
    while (accountFile >> name >> num) {
        accounts.emplace_back(name, num);
    }
}

void readTransaction(ifstream& transationFile, vector<Account>& accounts) {
    string name, text;
    int num, bankAcc, amount;
    bool accFlag;
    while (transationFile >> text) {
        accFlag = false;
        if (text == "Deposit") {
            transationFile >> bankAcc >> amount;
            for (Account& person : accounts) {
                if (person.getNumber() == bankAcc) {
                    person.deposit(amount);
                    accFlag = true;
                }
            }
            if (!accFlag) {
                cout << "Account does not exist" << endl;
            }
        }
        else if (text == "Withdraw") {
            transationFile >> bankAcc >> amount;
            for (Account& person : accounts) {
                if (person.getNumber() == bankAcc) {
                    person.withdraw(amount);
                    accFlag = true;
                }
            }
            if (!accFlag) {
                cout << "Account does not exist" << endl;
            }
        }
        else if (text == "Account") {
            transationFile >> name >> num;
            accounts.emplace_back(Account(name, num));
        }
        else {
            cout << "Invalid Operation" << endl;
        }
    }
}


void displayAccounts(const vector<Account>& accounts) {
    for (const Account& theAccount : accounts) {
        cout << theAccount << endl;
    }
}