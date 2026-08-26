#include "Bank.h"
#include <iostream>
#include <fstream>

Bank::Bank(){
    loadFromFile(fileName);
}

Bank::~Bank(){
    saveToFile(fileName);
}

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


bool Bank::transferMoney(int fromAccountNumber , int toAccountNumber , double amount){
    Account* sender = findAccount(fromAccountNumber); 
    if(sender == nullptr) return false;
    if(amount <= 0) return false;
    if(sender->getBalance() < amount) return false;
        Account* receiver = findAccount(toAccountNumber);
        if(receiver != nullptr && sender != receiver){
            if(sender->withdraw(amount) &&  receiver->deposit(amount)){
            return true;
            }
        }
    return false;    
}

bool Bank::deposit(int accountNumber, double amount){
    Account* account = findAccount(accountNumber);
    if(account ==  nullptr) return false;  
    return account->deposit(amount);        
}

bool Bank::withdraw(int accountNumber, double amount){
    Account* account = findAccount(accountNumber);
    if(account == nullptr) return false;
    return account->withdraw(amount);  
}

bool Bank::getBalance(int accountNumber, double& balance){
    Account* account = findAccount(accountNumber);
    if(account == nullptr) return false;
    balance = account->getBalance();
    return true;
}

bool Bank::saveToFile(const std::string& nameFile){
    std::ofstream file(nameFile);
    if(!file) return false;
    for(const Account& account : accounts){
        file << account.getAccountNumber() << " "
             << account.getOwnerName() << " "
             << account.getBalance() <<std::endl;
    }
    return true;
}

bool Bank::loadFromFile(const std::string& nameFile){
    std::ifstream file(nameFile);
    if(!file) return false;
    int accountNumber{};
    std::string ownerName{};
    double balance{};
    int maxAccountNumber = 0;
    bool anyLoaded = false ;
    while(file >> accountNumber >> ownerName >> balance)
    {        
        Account newAccount(ownerName,balance,accountNumber);
        accounts.push_back(newAccount);
        anyLoaded = true;
        if(accountNumber > maxAccountNumber){
            maxAccountNumber = accountNumber;
        }
    }
    if(anyLoaded) Account::setNextAccountNumber(maxAccountNumber);
    return true;
}