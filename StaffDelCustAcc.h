#ifndef STAFFDELCUSTACC_H
#define STAFFDELCUSTACC_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "StaffDashboard.h"

using namespace std;

class StaffDelCustAcc {
    public:
    int accNo;
    string name;
    string choice = "1";
    string choice2 = "2";

    StaffDelCustAcc();
};

#endif