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
    cout << "1. exit" << endl;
    
    cout << "Enter Choice: " << ends;
    cin >> choice;
    cout << endl;
    choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
    transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

    while(choice != "1"){
        cout << "Please select one of the options above: " << ends;
        cin >> choice;
        cout << endl;
    }

    if(choice == "1"){
        CustomerSignIn();
    }
}