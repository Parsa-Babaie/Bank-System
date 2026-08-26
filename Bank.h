#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <string>
#include <vector>

class Bank{
    private:
        std::vector<Account> accounts;
        Account* findAccount(int accountNumber);

        bool saveToFile(const std::string& nameFile);

        bool loadFromFile(const std::string& nameFile);

        const std::string fileName = "accounts.txt";

    public:

        Bank();
        
        ~Bank();

        bool createAccount(const std::string& ownerName, double initialBalance);

        void showAccounts() const;

        bool transferMoney(int fromAccountNumber , int toAccountNumber , double amount);

        bool deposit(int accountNumber, double amount);

        bool withdraw(int accountNumber, double amount);

        bool getBalance(int accountNumber, double& balance);
};







#endif