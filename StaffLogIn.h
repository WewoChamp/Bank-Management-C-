#ifndef STAFFLOGIN_H
#define STAFFLOGIN_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "StaffSignIn.h"
#include "StaffDashboard.h"

using namespace std;

class StaffLogIn {
    public:
    int accNo;
    string password;

    StaffLogIn();
};

#endif