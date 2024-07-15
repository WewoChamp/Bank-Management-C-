#include "Deposit.h"
using namespace std;

Deposit::Deposit(){
    while(choice == "1"){
        cout << "*******************************" << endl;
        cout << "Deposit" << endl;
        cout << "*******************************" << endl;
        cout << "Enter the amount you would like to deposit (eg. 3000) or 0 to go back: " << ends;
        cin >> addition;
        addition.erase(std::remove_if(addition.begin(), addition.end(), ::isspace), addition.end());
        transform(addition.begin(), addition.end(), addition.begin(), ::toupper);
        if(addition == "0"){
            CustomerDashboard();
        }
        newAmount = to_string(stoi(customerAccountDatabase.getAccInfo(genAccNo, "amount")) + stoi(addition));
        customerAccountDatabase.editInfo(genAccNo, "amount", newAmount);
        cout << addition << " successfully deposited." << endl;
        newAmount = customerAccountDatabase.getAccInfo(genAccNo, "amount");
        cout << "NEW ACCOUNT BALANCE: " << newAmount << endl;
        cout << "Enter 1 to make another deposit or any other key to go back to the dashboard: " << ends;
        cin >> choice;
        choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

        if(choice != "1"){
            CustomerDashboard();
        }
    }
}