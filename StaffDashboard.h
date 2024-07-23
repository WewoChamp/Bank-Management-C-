#ifndef STAFFDASHBOARD_H
#define STAFFDASHBOARD_H

#include <iostream>
#include <string>
#include "StaffSignIn.h"
#include "EditCustomerAccount.h"
#include "StaffMakeCustAcc.h"
#include "StaffTranForCust.h"
#include "StaffDelCustAcc.h"
#include "StaffSearchCustAcc.h"
#include "StaffPrintAllCustAcc.h"

using namespace std;

class StaffDashboard {
    private:
    string choice;

    public:
    string name;

    StaffDashboard();
};

#endif