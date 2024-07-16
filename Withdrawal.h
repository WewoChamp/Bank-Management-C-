#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "CustomerDashboard.h"

using namespace std;

class Withdrawal {
    public:
    string newAmount;
    string deduction;
    string choice = "1";

    Withdrawal();
};

#endif