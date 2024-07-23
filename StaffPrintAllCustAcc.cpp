#include "StaffPrintAllCustAcc.h"
using namespace std;

StaffPrintAllCustAcc::StaffPrintAllCustAcc(){
    cout << "*******************************" << endl;
    cout << "All Customers' Accounts" << endl;
    cout << "*******************************" << endl;
    customerAccountDatabase.printAcc();

    cout << "Enter any character to go back to the dashboard: " << ends;
    cin >> choiceCheck;
    choiceCheck.erase(std::remove_if(choiceCheck.begin(), choiceCheck.end(), ::isspace), choiceCheck.end());
    if(choiceCheck.size() > 0){
        choice = choiceCheck;
    }
    if(choice.size() > 0){
        StaffDashboard();
    }
}