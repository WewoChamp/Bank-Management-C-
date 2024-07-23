#include "StaffSearchCustAcc.h"
using namespace std;

StaffSearhCustAcc::StaffSearhCustAcc(){
    while(choice == "1"){
        cout << "*******************************" << endl;
        cout << "Search Customers' Accounts" << endl;
        cout << "*******************************" << endl;
        cout << "Enter the account number of the customer you would like to search for or 0 to go back: " << ends;
        cin >> accNo;
        cout << endl;
        while(!customerAccountDatabase.doesAccExist(accNo) && accNo != 0){
            cout << "ACCOUNT DOES NOT EXIST" << endl;
            cout << "Enter the account number of the customer you would like to search for or 0 to go back: " << ends;
            cin >> accNo;
            cout << endl;
        }

        if(accNo == 0){
            StaffDashboard();
        }

        cout << "ACCOUNT FOUND" << endl;

        customerAccountDatabase.searchAcc(accNo);

        cout << "Enter 1 to search for another customer's account or any other key to go back to the dashboard: " << ends;
        cin >> choice;
        choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

        if(choice != "1"){
            StaffDashboard();
        }
    }
}