#include "StaffTranForCust.h"
using namespace std;

StaffTranForCust::StaffTranForCust(){
    while (choice == "1"){
        cout << "*******************************" << endl;
        cout << "Transfer" << endl;
        cout << "*******************************" << endl;

        while(choice2 == "2"){
            cout << "Enter the account number of the cutomer you would like to transfer from or 0 to go back: " << ends;
            cin >> accNo1;
            while(!customerAccountDatabase.doesAccExist(accNo1) && accNo1 != 0){
                cout << "ACCOUNT DOES NOT EXIST!" << endl;
                cout << "Enter the account number of the cutomer you would like to transfer from or 0 to go back: " << ends;
                cin >> accNo1;
            }
            if(accNo1 == 0){
                StaffDashboard();
            }

            cout << "Enter the account number of the cutomer you would like to transfer to or 0 to go back: " << ends;
            cin >> accNo2;
            while(!customerAccountDatabase.doesAccExist(accNo2) && accNo2 != 0){
                cout << "ACCOUNT DOES NOT EXIST!" << endl;
                cout << "Enter the account number of the cutomer you would like to transfer to or 0 to go back: " << ends;
                cin >> accNo2;
            }
            if(accNo2 == 0){
                StaffDashboard();
            }

            name1 = customerAccountDatabase.getAccInfo(accNo1, "name");
            name2 = customerAccountDatabase.getAccInfo(accNo2, "name");

            cout << "Would you like to transfer money from " << name1 << " to " << name2 << "?" << endl;
            cout << "1. YES" << endl;
            cout << "2. NO" << endl;
            cout << "Enter choice: " << ends;
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

        while(choice3 == "2"){
            cout << "Enter the amount you would like to transfer from " << name1 << "'s account to " << name2 << " (eg. 3000) or 0 to go back: " << ends;
            cin >> deduction;
            deduction.erase(std::remove_if(deduction.begin(), deduction.end(), ::isspace), deduction.end());
            transform(deduction.begin(), deduction.end(), deduction.begin(), ::toupper);
            while (stoi(deduction) > stoi(customerAccountDatabase.getAccInfo(accNo1, "amount")) && stoi(deduction) != 0){
                cout << "INSUFFICIENT FUNDS IN " << name1 << "'s ACCOUNT!" << endl;
                cout << "Enter the amount you would like to transfer from " << name1 << "'s account to " << name2 << " (eg. 3000) or 0 to go back: " << ends;
                cin >> deduction;
                deduction.erase(std::remove_if(deduction.begin(), deduction.end(), ::isspace), deduction.end());
                transform(deduction.begin(), deduction.end(), deduction.begin(), ::toupper);
            }
            if(stoi(deduction) == 0){
                StaffDashboard();
            }

            cout << "Would you like to transfer " << deduction << " from " << name1 << "'s account to " << name2 << "'s account?" << endl;
            cout << "1. YES" << endl;
            cout << "2. NO" << endl;
            cout << "Enter choice: " << ends;
            cin >> choice3;
            choice3.erase(std::remove_if(choice3.begin(), choice3.end(), ::isspace), choice3.end());
            transform(choice3.begin(), choice3.end(), choice3.begin(), ::toupper);
            while(choice3 != "1" && choice3 != "2"){
                cout << "Please choose from the options above: " << ends;
                cin >> choice3;
                choice3.erase(std::remove_if(choice3.begin(), choice3.end(), ::isspace), choice3.end());
                transform(choice3.begin(), choice3.end(), choice3.begin(), ::toupper);
            }
        }

        newAmount1 = to_string(stoi(customerAccountDatabase.getAccInfo(accNo1, "amount")) - stoi(deduction));
        customerAccountDatabase.editInfo(accNo1, "amount", newAmount1);
        newAmount2 = to_string(stoi(customerAccountDatabase.getAccInfo(accNo2, "amount")) + stoi(deduction));
        customerAccountDatabase.editInfo(accNo2, "amount", newAmount2);

        cout << "Successfully transferred " << deduction << " from " << name1 << " to " << name2 << "." << endl;
        cout << name1 << "'s new account balance: " << customerAccountDatabase.getAccInfo(accNo1, "amount") << endl;
        cout << name2 << "'s new account balance: " << customerAccountDatabase.getAccInfo(accNo2, "amount") << endl;

        cout << "Enter 1 to make another transfer or any other key to go back to the dashboard: " << ends;
        cin >> choice;
        choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

        if(choice != "1"){
            StaffDashboard();
        }

        choice2 = "2";
        choice3 = "2";
    }
}