#ifndef CUSTOMERNEWACCOUNT_H
#define CUSTOMERNEWACCOUNT_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "CustomerSignIn.h"
#include "CustomerDashboard.h"
using namespace std;

class CustomerNewAccount{
    public:
    string password;
    string passwordCheck;
    string name;
    string amount;
    string dob;

    CustomerNewAccount();
};

#endif