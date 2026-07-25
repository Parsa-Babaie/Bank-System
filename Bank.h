#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <string>
#include <vector>

class Bank{
    private:
        std::vector<Account> accounts;
    public:
        bool createAccount(const std::string& ownerName, double initialBalance);

        Account* findAccount(int accountNumber);


};







#endif