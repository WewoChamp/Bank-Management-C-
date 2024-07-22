#ifndef STAFFMAKECUSTACC_H
#define STAFFMAKECUSTACC_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "StaffDashboard.h"

using namespace std;

class StaffMakeCustAcc {
    public:
    string password;
    string passwordCheck;
    string name;
    string amount;
    string dob;
    string choice = "1";

    StaffMakeCustAcc();
};

#endif