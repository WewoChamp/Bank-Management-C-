#include "StaffNewAccount.h"
using namespace std;

StaffNewAccount::StaffNewAccount(){
    cout << "*******************************" << endl;
    cout << "Staff Account Creation" << endl;
    cout << "*******************************" << endl;
    cout << "Enter your full name or 0 to go back: " << ends;
    getline(cin.ignore(1024, '\n'), name);
    cout << endl;
    if(name == "0"){
        StaffSignIn();
    }
    cout << "Enter your date of birth in the format DD-MM-YYYY(14-04-2023) or 0 to go back: " << ends;
    cin >> dob;
    cout << endl;
    if(dob == "0"){
        StaffSignIn();
    }
    cout << "Enter a password(without spaces) for your account or 0 to go back: " << ends;
    cin >> passwordCheck;
    cout << endl;
    if(passwordCheck == "0"){
        StaffSignIn();
    }
    cout << "Confirm password or 0 to go back: " << ends;
    cin >> password;
    cout << endl;
    if(password == "0"){
        StaffSignIn();
    }
    while(password != passwordCheck && password != "0"){
        cout << "PASSWORDS DO NOT MATCH" << endl;
        cout << "Confirm your password or enter 0 to go back: " << ends;
        cin >> password;
        cout << endl;
        if(password == "0"){
        StaffSignIn();
        }
    }
    amount = "0";
    genStaffAccNo++;
    staffAccountDatabase.insertAcc(genStaffAccNo, password, name, amount, dob);
    StaffDashboard();
}