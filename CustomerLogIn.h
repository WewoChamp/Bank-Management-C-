#ifndef CUSTOMERLOGIN_H
#define CUSTOMERLOGIN_H

#include <iostream>
#include <string>
#include "Accounts.h"
#include "CustomerDashboard.h"
#include "CustomerSignIn.h"
using namespace std;

class CustomerLogIn{
    public:
    int accNo;
    string password;

    CustomerLogIn();
};

#endif