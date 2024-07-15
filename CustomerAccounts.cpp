#include "CustomerAccounts.h"
#include <list>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

CustomerAccounts::CustomerAccounts(){
    
}

bool CustomerAccounts::isEmpty() const{
    int sum;

    for(int i = 0; i < noOfAccGroupings; i++){
        sum += customerAccounts[i].size();
    }

    if(!sum){
        return true;
    }
    return false;
}

int CustomerAccounts::accHash(int key){
    return key % noOfAccGroupings; //Hash determines the grouping that each
                                   //acc stays in
}

void CustomerAccounts::insertAcc(int accNo, string password, string name, string amount, string dob){
    int hashVal = accHash(accNo);
    auto& accDetails = customerAccounts[hashVal];
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

void CustomerAccounts::removeAcc(int accNo){
    int hashVal = accHash(accNo);
    auto& accDetails = customerAccounts[hashVal];
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

void CustomerAccounts::printAcc(){
    for(int i = 0; i < noOfAccGroupings; i++){
        if(customerAccounts[i].size() == 0) continue;

        auto accItr = begin(customerAccounts[i]);
        for(; accItr != end(customerAccounts[i]); accItr++){
            cout << "Account Number: " << accItr->first << endl;
            auto accItr2 = begin(accItr->second);
            for(; accItr2 != end(accItr->second); accItr2++){
                cout << accItr2->first << " : " << accItr2->second << endl;
            }
        }
    }
}

void CustomerAccounts::searchAcc(int accNo){
    int hashVal = accHash(accNo);
    auto& accDetails = customerAccounts[hashVal];
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

bool CustomerAccounts::doesAccExist(int accNo){
    if(isEmpty()){
        return false;
    }
    int hashVal = accHash(accNo);
    auto& accDetails = customerAccounts[hashVal];
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

bool CustomerAccounts::doesPasswordMatch(int accNo, string password){
    int hashVal = accHash(accNo);
    auto& accDetails = customerAccounts[hashVal];
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

string CustomerAccounts::getAccInfo(int accNo, string info){
    int hashVal = accHash(accNo);
    auto& accDetails = customerAccounts[hashVal];
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

void CustomerAccounts::editInfo(int accNo, string info, string change){
    int hashVal = accHash(accNo);
    auto& accDetails = customerAccounts[hashVal];
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

CustomerAccounts customerAccountDatabase;

int genAccNo = 0;