#include "HomePage.h"
using namespace std;

HomePage::HomePage(){
        while (logIn != "1" && logIn != "2" && logIn != "3" && logIn != "CUSTOMER" && logIn != "ADMIN" && logIn != "STAFF"){
            cout << "*******************************" << endl;
            cout << "Bank Management" << endl;
            cout << "*******************************" << endl;
            cout << "Sign in as: " << endl;
            cout << "1. Customer" << endl;
            cout << "2. Admin" << endl;
            cout << "3. Staff" << endl;
            
            cout << "Enter Choice : " << ends;
            cin >> logIn;
            cout << endl;
            logIn.erase(std::remove_if(logIn.begin(), logIn.end(), ::isspace), logIn.end());
            transform(logIn.begin(), logIn.end(), logIn.begin(), ::toupper);

            if(logIn == "1" || logIn == "CUSTOMER"){
                CustomerSignIn();
            }

            if(logIn == "2" || logIn == "ADMIN"){
                //Admin();
            }

            if(logIn == "3" || logIn == "STAFF"){
                //Staff();
            } 
        }
}