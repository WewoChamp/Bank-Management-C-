#include "EditCustomerAccount.h"
using namespace std;

EditCustomerAccount::EditCustomerAccount(){
    cout << "*******************************" << endl;
    cout << "Edit a Customer's Account" << endl;
    cout << "*******************************" << endl;
    while(choice == "1"){
        while(choice2 == "2"){
            cout << "Enter the account number of the person you would like to make changes for or 0 to go back: " << ends;
            cin >> accNo;
            cout << endl;
            while(!customerAccountDatabase.doesAccExist(accNo) && accNo != 0){
                cout << "ACCOUNT DOES NOT EXIST" << endl;
                cout << "Enter the account number of the person you would like to make changes for or 0 to go back: " << ends;
                cin >> accNo;
                cout << endl;
            }
            if(accNo == 0){
                StaffDashboard();
            }
            name = customerAccountDatabase.getAccInfo(accNo, "name");
            cout << "Would you like to make changes to " << name << "'s account?" << endl;
            cout << "1. YES" << endl;
            cout << "2. NO" << endl;
            cout << "Enter choice: " << ends;
            cin >> choice2;
            cout << endl;
            choice2.erase(std::remove_if(choice2.begin(), choice2.end(), ::isspace), choice2.end());
            transform(choice2.begin(), choice2.end(), choice2.begin(), ::toupper);
            while(choice2 != "1" && choice2 != "2"){
                cout << "Please choose from the options above: " << ends;
                cin >> choice2;
                choice2.erase(std::remove_if(choice2.begin(), choice2.end(), ::isspace), choice2.end());
                transform(choice2.begin(), choice2.end(), choice2.begin(), ::toupper);
            }
        }

        while(choice3 == "2"){
            cout << "Enter the info you would like to edit or 0 to exit: " << ends;
            cin >> infoDescription;
            cout << endl;
            infoDescription.erase(std::remove_if(infoDescription.begin(), infoDescription.end(), ::isspace), infoDescription.end());
            transform(infoDescription.begin(), infoDescription.end(), infoDescription.begin(), ::tolower);
            while(!customerAccountDatabase.doesParamExist(accNo, infoDescription) && infoDescription != "0"){
                cout << infoDescription << " DOES NOT EXIST FOR THIS CUSTOMER'S ACCOUNT." << endl;
                cout << "Enter the info you would like to edit or 0 to exit: " << ends;
                cin >> infoDescription;
                cout << endl;
                infoDescription.erase(std::remove_if(infoDescription.begin(), infoDescription.end(), ::isspace), infoDescription.end());
                transform(infoDescription.begin(), infoDescription.end(), infoDescription.begin(), ::tolower);
            }

            if(infoDescription == "0"){
                StaffDashboard();
            }

            cout << "Do you want to edit " << name << "'s " << infoDescription << "?" << endl;
            cout << "1. YES" << endl;
            cout << "2. NO" << endl;
            cout << "Enter choice: " << ends;
            cin >> choice3;
            cout << endl;
            choice3.erase(std::remove_if(choice3.begin(), choice3.end(), ::isspace), choice3.end());
            transform(choice3.begin(), choice3.end(), choice3.begin(), ::toupper);
            while(choice3 != "1" && choice3 != "2"){
                cout << "Please choose from the options above: " << ends;
                cin >> choice3;
                choice3.erase(std::remove_if(choice3.begin(), choice3.end(), ::isspace), choice3.end());
                transform(choice3.begin(), choice3.end(), choice3.begin(), ::toupper);
            }
        }

        cout << "Enter " << name << "'s updated " << infoDescription << ": " << ends;
        cin >> updatedInfo;
        customerAccountDatabase.editInfo(accNo, infoDescription, updatedInfo);
        cout << "Successfully updated " << name << "'s " << infoDescription << "." << endl;
        cout << "Enter 1 to edit another customer's account or any other key to go back to the dashboard: " << ends;
        cin >> choice;
        cout << endl;

        if(choice != "1"){
            StaffDashboard();
        }

        choice2 = "2";
        choice3 = "2";
    }
}