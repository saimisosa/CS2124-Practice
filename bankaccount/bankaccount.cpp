
#include "hello.h"

using namespace std;
// split into .cpp and .h files
int main() {
    bool isRunning = true;
    bool isBankOpen = false;
    char action;
    string amount;
    int pinNumber = 0;
    int pinManager = 0;
    int acc_number = 0;
    int interestRate = 0;

    while(isRunning){
        cout << "What do you want to do today?" << endl;
        cin >> action;

        switch(action){
            case 'o':
            case 'O':
                if (!isBankOpen){
                    cout << "The bank is closed." << endl;
                    break;
                }
                if (acc_objs.size()+1 > 100){
                    cout << "You cannot create more than 100 bank accounts." << endl;
                    break;
                }

                cout << "What's the initial amount that you want to deposit? " << endl;
                cin >> amount;

                cout << "Enter the pin number for the bank account (5 digits please)." << endl;
                cin >> pinNumber;
                while (pinNumber > 99999 || pinNumber < 10000){
                    cout << "Pin number too small! Please choose another." << endl;
                    cin >> pinNumber;
                }

                while (!openAccount(pinNumber, amount)){
                    cout << "Please enter a valid amount!" << endl;
                    cin >> amount;
                }

                break;
            case 'b':
            case 'B':
                cout << "Enter the account number of the account you want to view. " << endl;
                cin >> acc_number;
                findBankAccount(acc_number).bankInquiry();
                break;
            case 'd':
            case 'D':
                cout << "Enter the number of the bank account you want to deposit money in." << endl;
                cin >> acc_number;
                cout << "Enter the amount of money you want to deposit. " << endl;
                cin >> amount;
                cout << "Enter the pin number." << endl;
                cin >> pinNumber;

                while (!findBankAccount(acc_number).isCorrectPin(pinNumber)){
                    cout << "This isn't the correct pin. Enter again." << endl;
                    cin >> pinNumber;
                }

                findBankAccount(acc_number).makeDeposit(pinNumber, amount);
                break;
            case 'w':
            case 'W':
                cout << "Enter the number of the bank account you want to deposit withdraw from." << endl;
                cin >> acc_number;
                cout << "Enter the amount of money you want to withdraw. " << endl;
                cin >> amount;
                cout << "Enter the pin number." << endl;
                cin >> pinNumber;

                while (!findBankAccount(acc_number).isCorrectPin(pinNumber)){
                    cout << "This isn't the correct pin. Enter again." << endl;
                    cin >> pinNumber;
                }

                findBankAccount(acc_number).makeWithdrawal(pinNumber, amount);
                break;
            case 'c':
            case 'C':
                cout << "Enter the number of the bank account you want to close" << endl;
                cin >> acc_number;
                cout << "Enter the pin number." << endl;
                cin >> pinNumber;

                while (!findBankAccount(acc_number).isCorrectPin(pinNumber)){
                    cout << "This isn't the correct pin. Enter again." << endl;
                    cin >> pinNumber;
                }

                findBankAccount(acc_number).closeAccount(pinNumber);
                break;
            case 'i':
            case 'I':
                cout << "Enter the interest rate you want to apply in terms of percent. (ex. Input 20% as 20)" << endl;
                cin >> interestRate;
                cout << "Enter the managers pin." << endl;
                cin >> pinManager;
                applyInterest(pinManager, interestRate);
                break;
            case 'p':
            case 'P':
                cout << "Enter the manager's pin. " << endl;
                cin >> pinManager;
                cout << "Displaying all bank accounts." << endl;
                printAll(pinManager);
                break;
            case 'e':
            case 'E':
                cout << "Enter the manager's pin number." << endl;
                cin >> pinManager;
                cout << "Closing all bank accounts." << endl;
                closeAll(pinManager);
                isRunning = false;
                break;
            case 'l':
            case 'L':
                cout << "Thank you for banking with us! Have a nice day!" << endl;
                isRunning = false;
                break;
            case 'z':
            case 'Z':
                for (int i = 0; i < 100 ; ++i) {
                    openAccount(12345, "10000");
                }
                break;
            case 's':
            case 'S':
                cout << "Enter the manager's pin" << endl;
                cin >> pinManager;
                if (pinManager != managerPin){
                    cout << "That's not the right pin! Please enter the correct one." << endl;
                    cin >> pinManager;
                }
                isBankOpen = true;
                cout << "The bank is now open." << endl;
                break;
            default:
                cout << "Enter a valid letter" << endl;
                break;
        }
    }
}
