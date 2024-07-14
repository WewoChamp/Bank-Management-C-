#include "CustomerSignIn.h"
using namespace std;

CustomerSignIn::CustomerSignIn(){
        while(logIn != "1" && logIn != "2" && logIn != "3"){
            cout << "*******************************" << endl;
            cout << "Customer Sign in" << endl;
            cout << "*******************************" << endl;
            cout << "Would you like to" << endl;
            cout << "1. Log in as an existing customer." << endl;
            cout << "2. Create a new account." << endl;
            cout << "3. exit" << endl;

            cout << "Enter Choice : " << ends;
            cin >> logIn;
            cout << endl;
            logIn.erase(std::remove_if(logIn.begin(), logIn.end(), ::isspace), logIn.end());
            transform(logIn.begin(), logIn.end(), logIn.begin(), ::toupper);

            if(logIn == "1"){
                CustomerLogIn();
            }
            if(logIn == "2"){
                CustomerNewAccount();
            }
            if(logIn == "3"){
                HomePage();
            }
        }
}