#ifndef CUSTOMERACCOUNTS_H
#define CUSTOMERACCOUNTS_H

#include <iostream>
#include <list>
#include <vector>
#include <cstring>
using namespace std;

//Hashtable of account detail

class CustomerAccounts {
    private:
    //Stores accounts in groups
    static const int noOfAccGroupings = 10;
    list<pair<int, list<pair<string, string> > > > customerAccounts[noOfAccGroupings];

    public:
    bool isEmpty() const;
    int accHash (int accNo);
    void insertAcc (int accNo, string password, string name, string amount, string dob);
    void removeAcc (int accNo);
    void searchAcc (int accNo);
    void printAcc ();
    bool doesAccExist(int accNo);
    bool doesPasswordMatch(int accNo, string password);
    string getAccInfo (int accNo, string info);
    CustomerAccounts();

};

extern CustomerAccounts customerAccountDatabase;
extern int genAccNo;

#endif