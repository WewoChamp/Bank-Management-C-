#ifndef STAFFTRANFORCUST_H
#define STAFFTRANFORCUST_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "StaffDashboard.h"

using namespace std;

class StaffTranForCust {
    public:
    int accNo1;
    int accNo2;
    string deduction;
    string newAmount1;
    string newAmount2;
    string name1;
    string name2;
    string choice = "1";
    string choice2 = "2";
    string choice3 = "2";

    StaffTranForCust();
};

#endif