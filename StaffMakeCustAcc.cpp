#include "StaffMakeCustAcc.h"
using namespace std;

StaffMakeCustAcc::StaffMakeCustAcc(){
    cout << "*******************************" << endl;
    cout << "Customer Account Creation" << endl;
    cout << "*******************************" << endl;
    while(choice == "1"){
        cout << "Enter the full name of the customer or 0 to go back: " << ends;
        getline(cin.ignore(1024, '\n'), name);
        cout << endl;
        if(name == "0"){
            StaffDashboard();
        }
        cout << "Enter the date of birth of the customer in the format DD-MM-YYYY(14-04-2023) or 0 to go back: " << ends;
        cin >> dob;
        cout << endl;
        if(dob == "0"){
            StaffDashboard();
        }
        cout << "Enter the initial amount of money the customer is depositing into their account (e.g. 1000) the minimum is 1, or 0 to go back: " << ends;
        cin >> amount;
        cout << endl;
        if(amount == "0"){
            StaffDashboard();
        }
        cout << "Enter a password(without spaces) for the customer's account or 0 to go back: " << ends;
        cin >> passwordCheck;
        cout << endl;
        if(passwordCheck == "0"){
            StaffDashboard();
        }
        cout << "Confirm password or 0 to go back: " << ends;
        cin >> password;
        cout << endl;
        if(password == "0"){
            StaffDashboard();
        }
        while(password != passwordCheck && password != "0"){
            cout << "PASSWORDS DO NOT MATCH" << endl;
            cout << "Confirm password or enter 0 to go back: " << ends;
            cin >> password;
            cout << endl;
            if(password == "0"){
            StaffDashboard();
            }
        }
        genAccNo++;
        customerAccountDatabase.insertAcc(genAccNo, password, name, amount, dob);
        cout << "Enter 1 to make another customer account or any other key to go back: " << endl;
        cin >> choice;
        if(choice != "1"){
            StaffDashboard();
        }
    }
}