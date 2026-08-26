#include "account.h"

int Account::nextAccountNumber = 1001;


Account::Account(const std::string& newOwnerName, double newBalance)
            :ownerName(newOwnerName),
             accountNumber(nextAccountNumber++),
             balance(newBalance){}

Account::Account(const std::string& newOwnerName, double newBalance, int newAccountNumber)
            :ownerName(newOwnerName),
             accountNumber(newAccountNumber),
             balance(newBalance){}

void Account::setNextAccountNumber(int accountNumber){
    nextAccountNumber = accountNumber + 1; 
}             

std::string Account::getOwnerName() const{
    return ownerName;
}
void Account::setOwnerName(const std::string& newOwnerName){
    ownerName = newOwnerName;
}

double Account::getBalance() const{
    return balance;
}

bool Account::deposit(double amount){
    if(amount <= 0) return false;
    balance += amount;
    return true;
}

bool Account::withdraw(double amount){
    if(amount <= 0) return false;
    if(amount > balance) return false;
    balance -= amount;
    return true;
}

int Account::getAccountNumber() const{
    return accountNumber;
}
