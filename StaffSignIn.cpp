#include "StaffSignIn.h"
using namespace std;

StaffSignIn::StaffSignIn(){
    while(logIn != "1" && logIn != "2" && logIn != "3"){
        cout << "*******************************" << endl;
        cout << "Staff Sign in" << endl;
        cout << "*******************************" << endl;
        cout << "Would you like to" << endl;
        cout << "1. Log in as an existing staff member." << endl;
        cout << "2. Create a new staff account." << endl;
        cout << "3. exit" << endl;

        cout << "Enter Choice : " << ends;
        cin >> logIn;
        cout << endl;
        logIn.erase(std::remove_if(logIn.begin(), logIn.end(), ::isspace), logIn.end());
        transform(logIn.begin(), logIn.end(), logIn.begin(), ::toupper);

        if(logIn == "1"){
            StaffLogIn();
        }
        if(logIn == "2"){
            StaffNewAccount();
        }
        if(logIn == "3"){
            HomePage();
        }
    }
}