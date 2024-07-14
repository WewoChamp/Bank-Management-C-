#include "CustomerLogIn.h"
using namespace std;

CustomerLogIn::CustomerLogIn(){
        cout << "*******************************" << endl;
        cout << "Customer Log in" << endl;
        cout << "*******************************" << endl;
        cout << "Enter Acc No or 0 to go back: " << ends;
        cin >> accNo;
        cout << endl;
        while(!customerAccountDatabase.doesAccExist(accNo) && accNo != 0){
            cout << "ACCOUNT DOES NOT EXIST" << endl;
            cout << "Enter Acc No or 0 to go back: " << ends;
            cin >> accNo;
            cout << endl;
        }
        if(accNo == 0){
            CustomerSignIn();
        }
        cout << "Enter Password or 0 to go back: " << ends;
        cin >> password;
        cout << endl;
        while(!customerAccountDatabase.doesPasswordMatch(accNo, password) && password != "0"){
            cout << "INCORRECT PASSWORD" << endl;
            cout << "Enter Password or 0 to go back: " << ends;
            cin >> password;
            cout << endl;
        }
        if(password == "0"){
            CustomerSignIn();
        }
        if(customerAccountDatabase.doesPasswordMatch(accNo, password)){
            CustomerDashboard();
        }
}