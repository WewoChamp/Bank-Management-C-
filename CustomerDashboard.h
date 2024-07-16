#ifndef CUSTOMERDASHBOARD_H
#define CUSTOMERDASHBOARD_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "CustomerSignIn.h"
#include "Deposit.h"
#include "Withdrawal.h"
#include "Transfer.h"

using namespace std;

class CustomerDashboard{
    private:
    string choice;

    public:
    string name;
    string amount;

    CustomerDashboard();
};

#endif