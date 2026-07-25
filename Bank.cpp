#include "Bank.h"
#include <iostream>

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

void Bank::showAccounts() const{
    for(const Account& account : accounts){
        std::cout<<account.getAccountNumber()<<"\t"
                 <<account.getOwnerName()<<"\t"
                 <<account.getBalance()<<std::endl;   
    }
}