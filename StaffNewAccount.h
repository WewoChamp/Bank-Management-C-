#ifndef STAFFNEWACCOUNT_H
#define STAFFNEWACCOUNT_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "StaffSignIn.h"
#include "StaffDashboard.h"

using namespace std;

class StaffNewAccount {
    public:
    string password;
    string passwordCheck;
    string name;
    string amount;
    string dob;

    StaffNewAccount();
};

#endif