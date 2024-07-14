#include "CustomerNewAccount.h"
using namespace std;

CustomerNewAccount::CustomerNewAccount(){
    cout << "*******************************" << endl;
    cout << "Customer Account Creation" << endl;
    cout << "*******************************" << endl;
    cout << "Enter your full name or 0 to go back: " << ends;
    getline(cin.ignore(1024, '\n'), name);
    cout << endl;
    if(name == "0"){
        CustomerSignIn();
    }
    cout << "Enter your date of birth in the format DD-MM-YYYY(14-04-2023) or 0 to go back: " << ends;
    cin >> dob;
    cout << endl;
    if(dob == "0"){
        CustomerSignIn();
    }
    cout << "Enter the initial amount of money you are depositing into your account (e.g. 1000) the minimum is 1, or 0 to go back: " << ends;
    cin >> amount;
    cout << endl;
    if(amount == "0"){
        CustomerSignIn();
    }
    cout << "Enter a password(without spaces) for your account or 0 to go back: " << ends;
    cin >> passwordCheck;
    cout << endl;
    if(passwordCheck == "0"){
        CustomerSignIn();
    }
    cout << "Confirm password or 0 to go back: " << ends;
    cin >> password;
    cout << endl;
    if(password == "0"){
        CustomerSignIn();
    }
    while(password != passwordCheck && password != "0"){
        cout << "PASSWORDS DO NOT MATCH" << endl;
        cout << "Confirm your password or enter 0 to go back: " << ends;
        cin >> password;
        cout << endl;
        if(password == "0"){
        CustomerSignIn();
        }
    }
    genAccNo++;
    customerAccountDatabase.insertAcc(genAccNo, password, name, amount, dob);
    CustomerDashboard();
}