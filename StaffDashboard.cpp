#include "StaffDashboard.h"
using namespace std;

StaffDashboard::StaffDashboard(){
    cout << "*******************************" << endl;
    cout << "Staff Dashboard" << endl;
    cout << "*******************************" << endl;
    name = staffAccountDatabase.getAccInfo(genStaffAccNo, "name");
    cout << "WELCOME " + name + "!" << endl;
    cout << "*******************************" << endl;
    cout << "ACCOUNT NUMBER: " << genStaffAccNo << endl;
    cout << "*******************************" << endl;
    cout << "*******************************" << endl;
    cout << "What would you like to do today?" << endl;
    cout << "1. Edit a customer account." << endl;
    cout << "2. Make a transfer on behalf of a customer." << endl;
    cout << "3. Create a new customer account" << endl;
    cout << "4. Delete a customer account." << endl;
    cout << "5. Search for a customer account." << endl;
    cout << "6. Print out all customer accounts." << endl;
    cout << "7. Exit to sign in page." << endl;

    cout << "Enter Choice: " << ends;
    cin >> choice;
    cout << endl;
    choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
    transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

    while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7"){
        cout << "Please select one of the options above: " << ends;
        cin >> choice;
        cout << endl;
    }

    if(choice == "1"){
        EditCustomerAccount();
    }

    if(choice == "2"){
        StaffTranForCust();
    }

    if (choice == "3"){
        StaffMakeCustAcc();
    }

    if(choice == "7"){
        StaffSignIn();
    }
}