#include "Bank.h"


bool Bank::createAccount(const std::string& ownerName, double initialBalance){
    if(initialBalance < 0 ) return false;
    Account newAccount(ownerName, initialBalance);
    accounts.push_back(newAccount);
    return true;
}

Account* Bank::findAccount(int accountNumber){
    for(Account& account : accounts){
        if(account.getAccountNumber() == accountNumber)
        return &account;
    }
    return nullptr;
}