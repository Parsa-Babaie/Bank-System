#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>


class Account{
    private:
        std::string ownerName;
        int accountNumber;
        double balance;
        static int nextAccountNumber;

    public:
        Account(const std::string& newOwnerName , double newBalance);
        
        void setOwnerName(const std::string& newOwnerName);
        
        std::string getOwnerName() const;
        
        double getBalance() const; 

        bool deposit(double amount);

        bool withdraw(double amount);

        int getAccountNumber() const;
};




#endif