#include "StaffDelCustAcc.h"
using namespace std;

StaffDelCustAcc::StaffDelCustAcc(){
    while(choice == "1"){
        cout << "*******************************" << endl;
        cout << "Delete a Customer's Account" << endl;
        cout << "*******************************" << endl;

        while(choice2 == "2"){
            cout << "Enter the account number of the account you would like to delete or 0 to go back: " << ends;
            cin >> accNo;
            cout << endl;
            while(!customerAccountDatabase.doesAccExist(accNo) && accNo != 0){
                cout << "ACCOUNT DOES NOT EXIST" << endl;
                cout << "Enter the account number of the account you would like to delete or 0 to go back: " << ends;
                cin >> accNo;
                cout << endl;
            } 

            if(accNo == 0){
                StaffDashboard();
            }

            name = customerAccountDatabase.getAccInfo(accNo, "name");
            cout << "Do you want to delete " << name << "'s account?" << endl;
            cout << "1. YES" << endl;
            cout << "2. NO" << endl;
            cout << "Enter Choice: " << ends;
            cin >> choice2;
            choice2.erase(std::remove_if(choice2.begin(), choice2.end(), ::isspace), choice2.end());
            transform(choice2.begin(), choice2.end(), choice2.begin(), ::toupper);
            while(choice2 != "1" && choice2 != "2"){
                cout << "Please choose from the options above: " << ends;
                cin >> choice2;
                choice2.erase(std::remove_if(choice2.begin(), choice2.end(), ::isspace), choice2.end());
                transform(choice2.begin(), choice2.end(), choice2.begin(), ::toupper);
            }
        }

        customerAccountDatabase.removeAcc(accNo);
        cout << name << "'s account successfully deleted." << endl;
        cout << "Enter 1 to delete another customer's account or any other key to go back to the dashboard: " << ends;
        cin >> choice;
        choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

        if(choice != "1"){
            StaffDashboard();
        }
    }
}