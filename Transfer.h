#ifndef TRANSFER_H
#define TRANSFER_H

#include <iostream>
#include <string>
#include "CustomerAccounts.h"
#include "CustomerDashboard.h"

using namespace std;

class Transfer {
    public:
    int accNo;
    string deduction;
    string newAmount1;
    string newAmount2;
    string choice = "1";
    string choice2 = "2";
    string choice3 = "2";
    string name;

    Transfer();
};

#endif