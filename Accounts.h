#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

//Hashtable of account detail

class Accounts {
    private:
    //Stores accounts in groups
    static const int noOfAccGroupings = 10;
    list<pair<int, list<pair<string, string> > > > accounts[noOfAccGroupings];

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
    void editInfo (int accNo, string info, string change);
    Accounts();

};

extern Accounts customerAccountDatabase;
extern int genAccNo;

extern Accounts staffAccountDatabase;
extern int genStaffAccNo;

#endif