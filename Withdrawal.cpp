#include "Withdrawal.h"
using namespace std;

Withdrawal::Withdrawal(){
    while(choice == "1"){
        cout << "*******************************" << endl;
        cout << "Withdrawal" << endl;
        cout << "*******************************" << endl;
        cout << "Enter the amount you would like to withdraw (eg. 3000) or 0 to go back: " << ends;
        cin >> deduction;
        deduction.erase(std::remove_if(deduction.begin(), deduction.end(), ::isspace), deduction.end());
        transform(deduction.begin(), deduction.end(), deduction.begin(), ::toupper);
        while (stoi(deduction) > stoi(customerAccountDatabase.getAccInfo(genAccNo, "amount")) && stoi(deduction) != 0){
            cout << "INSUFFICIENT FUNDS." << endl;
            cout << "Enter the amount you would like to withdraw (eg. 3000) or 0 to go back: " << ends;
            cin >> deduction;
            deduction.erase(std::remove_if(deduction.begin(), deduction.end(), ::isspace), deduction.end());
            transform(deduction.begin(), deduction.end(), deduction.begin(), ::toupper);
        }
        if(deduction == "0"){
            CustomerDashboard();
        }
        newAmount = to_string(stoi(customerAccountDatabase.getAccInfo(genAccNo, "amount")) - stoi(deduction));
        customerAccountDatabase.editInfo(genAccNo, "amount", newAmount);
        cout << deduction << " successfully withdrawn." << endl;
        newAmount = customerAccountDatabase.getAccInfo(genAccNo, "amount");
        cout << "NEW ACCOUNT BALANCE: " << newAmount << endl;
        cout << "Enter 1 to make another withdrawal or any other key to go back to the dashboard: " << ends;
        cin >> choice;
        choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

        if(choice != "1"){
            CustomerDashboard();
        }
    }
}