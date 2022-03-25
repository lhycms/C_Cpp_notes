# 1. 练习 1：银行app
```c++
#include <iostream>
using namespace std;

void showMenu();


int main() {
    // init the bank account
    int balance = 500;
    int option;

    do {
        // display everytime you start a new loop
        showMenu()
        cout << "Option: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Balance is " << balance << endl;
                // You must break in case.
                break;
            case 2:
                cout << "Deposit amount: ";
                double depositeAmount;
                cin >> depositeAmount;
                balance += depositeAmount;
                break;
            case 3:
                cout << "Withdraw amount: ";
                double withdrawAmount;
                cin >> withdrawAmount;
                if (balance > withdrawAmount)
                    balance -= withdrawAmount;
                else
                    cout << "You balance is not enough" << endl;
                break;
            case 4:
                cout << "Exit.";
                break;
            default:
                cout << "Please read MENU!!!" << endl;
                break;
        }
    }while (option!=4);

    return 0;
}


void showMenu() {
    // display the header of menu
    for (int i = 0; i < 10; i++) 
        cout << '*';
    cout << "MENU";
    for (int i = 0; i < 10; i++)
        cout << '*';
    cout << endl;

    // display the functions of this bank app
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;

    // display the end of menu
    for (int i = 0; i < 24; i++)
        cout << '*';
    cout << endl;
}
```