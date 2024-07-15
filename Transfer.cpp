#include "Transfer.h"
using namespace std;

Transfer::Transfer(){
    while(choice == "1"){
        cout << "*******************************" << endl;
        cout << "Transfer" << endl;
        cout << "*******************************" << endl;
        
        while(choice2 == "2"){
            cout << "Enter the account number of the person you would like to transfer to or 0 to go back: " << ends;
            cin >> accNo;
            cout << endl;
            while(!customerAccountDatabase.doesAccExist(accNo) && accNo != 0){
                cout << "ACCOUNT DOES NOT EXIST" << endl;
                cout << "Enter Acc No of the person you would like to transfer to or 0 to go back: " << ends;
                cin >> accNo;
                cout << endl;
            }
            if(accNo == 0){
                CustomerDashboard();
            }
            name = customerAccountDatabase.getAccInfo(accNo, "name");
            cout << "Would you like to transfer to " << name << "?" << endl;
            cout << "1. YES." << endl;
            cout << "2. NO."  << endl;
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
            cout << "Enter the amount you would like to transfer to " << name << " (eg. 3000) or 0 to go back: " << ends;
            cin >> deduction;
            deduction.erase(std::remove_if(deduction.begin(), deduction.end(), ::isspace), deduction.end());
            transform(deduction.begin(), deduction.end(), deduction.begin(), ::toupper);
            while (stoi(deduction) > stoi(customerAccountDatabase.getAccInfo(genAccNo, "amount")) && stoi(deduction) != 0){
                cout << "INSUFFICIENT FUNDS." << endl;
                cout << "Enter the amount you would like to transfer to " << name << " (eg. 3000) or 0 to go back: " << ends;
                cin >> deduction;
                deduction.erase(std::remove_if(deduction.begin(), deduction.end(), ::isspace), deduction.end());
                transform(deduction.begin(), deduction.end(), deduction.begin(), ::toupper);
            }
            if(deduction == "0"){
                CustomerDashboard();
            }
            cout << "Would you like to transfer " << deduction << " to " << name << "?" << endl;
            cout << "1. YES." << endl;
            cout << "2. NO." << endl;
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

        newAmount1 = to_string(stoi(customerAccountDatabase.getAccInfo(accNo, "amount")) + stoi(deduction));
        customerAccountDatabase.editInfo(accNo, "amount", newAmount1);
        newAmount2 = to_string(stoi(customerAccountDatabase.getAccInfo(genAccNo, "amount")) - stoi(deduction));
        customerAccountDatabase.editInfo(genAccNo, "amount", newAmount2);

        cout << "Successfully transferred " << deduction << " to " << name << "." << endl;

        cout << "NEW ACCOUNT BALANCE: " << newAmount2 << endl;
        cout << "Enter 1 to make another transfer or any other key to go back to the dashboard: " << ends;
        cin >> choice;
        choice.erase(std::remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

        if(choice != "1"){
            CustomerDashboard();
        }

        choice2 = "2";
        choice3 = "2";
    }
}