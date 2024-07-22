#ifndef EDITCUSTOMERACCOUNT_H
#define EDITCUSTOMERACCOUNT_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "StaffDashboard.h"

using namespace std;

class EditCustomerAccount {
    public:
    int accNo;
    string infoDescription;
    string updatedInfo;
    string name;
    string choice = "1";
    string choice2 = "2";
    string choice3 = "2";

    EditCustomerAccount();
};

#endif