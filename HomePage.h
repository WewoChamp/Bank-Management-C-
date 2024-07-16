#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "CustomerSignIn.h"
#include "StaffSignIn.h"
using namespace std;

class HomePage{
    private:
    string logIn; //choose whether to log in as a staff or customer

    public:
    HomePage();
};

#endif