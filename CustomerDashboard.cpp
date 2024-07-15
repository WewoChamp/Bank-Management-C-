#include "CustomerDashboard.h"
using namespace std;

CustomerDashboard::CustomerDashboard(){
    cout << "*******************************" << endl;
    cout << "Customer Dashboard" << endl;
    cout << "*******************************" << endl;
    name = customerAccountDatabase.getAccInfo(genAccNo, "name");
    cout << "WELCOME " + name + "!" << endl;
    cout << "*******************************" << endl;
    cout << "ACCOUNT NUMBER: " << genAccNo << endl;
    cout << "*******************************" << endl;
    amount = customerAccountDatabase.getAccInfo(genAccNo, "amount");
    cout << "ACCOUNT BALANCE: " << amount << endl;
    cout << "*******************************" << endl;
    cout << "What would you like to do today?" << endl;
    cout << "1. Make a deposit." << endl;
    cout << "2. Make a withdrawal." << endl;
    cout << "3. Make a Transfer." << endl;
    cout << "4. Exit to sign in page." << endl;
    
    cout << "Enter Choice: " << ends;
    cin >> choice;
    cout << endl;
    choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
    transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

    while(choice != "1" && choice != "2" && choice != "3" && choice != "4"){
        cout << "Please select one of the options above: " << ends;
        cin >> choice;
        cout << endl;
    }

    if(choice == "1"){
        Deposit();
    }

    if(choice == "2"){
        Withdrawal();
    }

    if(choice == "3"){
        Transfer();
    }

    if(choice == "4"){
        CustomerSignIn();
    }
}