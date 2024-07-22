#include "Accounts.h"
#include <list>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

Accounts::Accounts(){
    
}

bool Accounts::isEmpty() const{
    int sum;

    for(int i = 0; i < noOfAccGroupings; i++){
        sum += accounts[i].size();
    }

    if(!sum){
        return true;
    }
    return false;
}

int Accounts::accHash(int key){
    return key % noOfAccGroupings; //Hash determines the grouping that each
                                   //acc stays in
}

void Accounts::insertAcc(int accNo, string password, string name, string amount, string dob){
    int hashVal = accHash(accNo);
    auto& accDetails = accounts[hashVal];
    auto accItr = begin(accDetails);
    bool accExists = false;
    
    for(; accItr != end(accDetails); accItr++){
        if(accItr->first == accNo){
            accExists = true;
            cout << "ACCOUNT ALREADY EXISTS." << endl;
            break;
        }
    }

    if(!accExists){
        accDetails.push_back(pair<int, list<pair<string, string> > >(accNo, list<pair<string, string> >()));
        accDetails.back().second.push_back(pair<string, string> ("name", name));
        accDetails.back().second.push_back(pair<string, string>("dob", dob));
        accDetails.back().second.push_back(pair<string, string>("amount", amount));
        accDetails.back().second.push_back(pair<string, string>("password", password));
        cout << "ACCOUNT CREATED." << endl;
    }
}

void Accounts::removeAcc(int accNo){
    int hashVal = accHash(accNo);
    auto& accDetails = accounts[hashVal];
    auto accItr = begin(accDetails);
    bool accExists = false;
    
    for(; accItr != end(accDetails); accItr++){
        if(accItr->first == accNo){
            accExists = true;
            accItr = accDetails.erase(accItr);
            cout << "ACCOUNT DELETED." << endl;
            break;
        }
    }

    if(!accExists){
        cout << "NO ACCOUNT FOUND. NO ACCOUNT DELETED." << endl;
    }
}

void Accounts::printAcc(){
    for(int i = 0; i < noOfAccGroupings; i++){
        if(accounts[i].size() == 0) continue;

        auto accItr = begin(accounts[i]);
        for(; accItr != end(accounts[i]); accItr++){
            cout << "Account Number: " << accItr->first << endl;
            auto accItr2 = begin(accItr->second);
            for(; accItr2 != end(accItr->second); accItr2++){
                cout << accItr2->first << " : " << accItr2->second << endl;
            }
        }
    }
}

void Accounts::searchAcc(int accNo){
    int hashVal = accHash(accNo);
    auto& accDetails = accounts[hashVal];
    auto accItr = begin(accDetails);
    bool accExists = false;

    for(; accItr != end(accDetails); accItr++){
        if(accItr->first == accNo){
            accExists = true;
            cout << "Account Number: " << accItr->first << endl;
            auto accItr2 = begin(accItr->second);
            for(; accItr2 != end(accItr->second); accItr2++){
                cout << accItr2->first << " : " << accItr2->second << endl;
            }
        }
    }

    if(!accExists){
        cout << "NO ACCOUNT FOUND" << endl;
    }
}

bool Accounts::doesAccExist(int accNo){
    if(isEmpty()){
        return false;
    }
    int hashVal = accHash(accNo);
    auto& accDetails = accounts[hashVal];
    auto accItr = begin(accDetails);
    bool accExists = false;
    
    for(; accItr != end(accDetails); accItr++){
        if(accItr->first == accNo){
            accExists = true;
            break;
        }
    }

    return accExists;
}

bool Accounts::doesPasswordMatch(int accNo, string password){
    int hashVal = accHash(accNo);
    auto& accDetails = accounts[hashVal];
    auto accItr = begin(accDetails);
    bool isMatch = false;

    for(; accItr != end(accDetails); accItr++){
        if(accItr->first == accNo){
            auto accItr2 = begin(accItr->second);
            for(; accItr2 != end(accItr->second); accItr2++){
                if(accItr2->first == "password"){
                    if(accItr2->second == password){
                        isMatch = true;
                        break;
                    }
                }
            }
            break;
        }
    }

    return isMatch;
}

string Accounts::getAccInfo(int accNo, string info){
    int hashVal = accHash(accNo);
    auto& accDetails = accounts[hashVal];
    auto accItr = begin(accDetails);
    string info1;

    for(; accItr != end(accDetails); accItr++){
        if(accItr->first == accNo){
            auto accItr2 = begin(accItr->second);
            for(; accItr2 != end(accItr->second); accItr2++){
                if(accItr2->first == info){
                    info1 = accItr2->second;
                    break;
                }
            }
            break;
        }
    }

    return info1;
}

void Accounts::editInfo(int accNo, string info, string change){
    int hashVal = accHash(accNo);
    auto& accDetails = accounts[hashVal];
    auto accItr = begin(accDetails);

    for(; accItr != end(accDetails); accItr++){
        if(accItr->first == accNo){
            auto accItr2 = begin(accItr->second);
            for(; accItr2 != end(accItr->second); accItr2++){
                if(accItr2->first == info){
                    (accItr2->second).assign(change);
                    break;
                }
            }
            break;
        }
    }
}

bool Accounts::doesParamExist(int accNo, string param){
    int hashVal = accHash(accNo);
    auto& accDetails = accounts[hashVal];
    auto accItr = begin(accDetails);
    bool paramExists = false;

    for(; accItr != end(accDetails); accItr++){
        if(accItr->first == accNo){
            auto accItr2 = begin(accItr->second);
            for(; accItr2 != end(accItr->second); accItr2++){
                if(accItr2->first == param){
                    paramExists = true;
                    break;
                }
            }
            break;
        }
    }

    return paramExists;
}

Accounts customerAccountDatabase;

int genAccNo = 0;

Accounts staffAccountDatabase;

int genStaffAccNo = 0;