#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "CustomerDashboard.h"

using namespace std;

class Deposit{
    public:
    string addition;
    string newAmount;
    string choice = "1";

    Deposit();
};

#endif