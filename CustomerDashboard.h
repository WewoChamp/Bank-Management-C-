#ifndef CUSTOMERDASHBOARD_H
#define CUSTOMERDASHBOARD_H

#include <iostream>
#include <string>
#include "CustomerAccounts.h"
#include "CustomerSignIn.h"

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