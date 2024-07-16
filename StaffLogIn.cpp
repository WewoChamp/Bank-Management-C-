#include "StaffLogIn.h"
using namespace std;

StaffLogIn::StaffLogIn(){
    cout << "*******************************" << endl;
    cout << "Staff Log in" << endl;
    cout << "*******************************" << endl;
    cout << "Enter Acc No or 0 to go back: " << ends;
    cin >> accNo;
    cout << endl;
    while(!staffAccountDatabase.doesAccExist(accNo) && accNo != 0){
        cout << "ACCOUNT DOES NOT EXIST" << endl;
        cout << "Enter Acc No or 0 to go back: " << ends;
        cin >> accNo;
        cout << endl;
    }
    if(accNo == 0){
        StaffSignIn();
    }
    genStaffAccNo = accNo;
    cout << "Enter Password or 0 to go back: " << ends;
    cin >> password;
    cout << endl;
    while(!staffAccountDatabase.doesPasswordMatch(accNo, password) && password != "0"){
        cout << "INCORRECT PASSWORD" << endl;
        cout << "Enter Password or 0 to go back: " << ends;
        cin >> password;
        cout << endl;
    }
    if(password == "0"){
        StaffSignIn();
    }
    if(staffAccountDatabase.doesPasswordMatch(accNo, password)){
        StaffDashboard();
    }
}