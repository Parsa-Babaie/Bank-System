#include <iostream>
#include <limits>
#include "Bank.h"
void showInfo(){
    std::cout<<"\n===== Bank-System =====\n"<<std::endl;
    std::cout<<"1. Creat Account\n"<<std::endl;
    std::cout<<"2. Show All accounts\n"<<std::endl;
    std::cout<<"3. Show Balance\n"<<std::endl;
    std::cout<<"4. Deposite\n"<<std::endl;
    std::cout<<"5. Withdraw\n"<<std::endl;
    std::cout<<"6. Transfer Money\n"<<std::endl;
    std::cout<<"0. Exit\n"<<std::endl;
}
int main(){
    int choice;
    Bank bank;
    bool running = true;
    while(running){
        showInfo();
        std::cout<<"Enter your choice: ";
        if(!(std::cin>>choice)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
        }
        switch (choice)
        {
        case 1:
        {
            std::string name;
            double amount;
            std::cout<<"Enter your name: ";
            std::cin>>name;
            std::cout<<"Enter your amount: ";
            if(!(std::cin>>amount)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            } 
            if(bank.createAccount(name,amount)){
                std::cout<<"Your Account created successfuly"<<std::endl;
            }
            else{
                std::cout<<"Failed to create account."<<std::endl;
            }
            
            break;
        }    
        case 2:
        {
            bank.showAccounts();
            break;
        }    
        case 3:
        {
            double balance{};
            int accountNumber{};
            std::cout<<"Enter your account number: ";
            if(!(std::cin>>accountNumber)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            }
            if(bank.getBalance(accountNumber, balance)){
                std::cout<<"Your Balance is: "<<balance<<std::endl;
            }
            else{
                std::cout<<"Error."<<std::endl;
            }
            break;
        }    
        case 4:
        {
            int accountNumber{};
            double amount{};
            std::cout<<"Enter your account number: ";
            if(!(std::cin>>accountNumber)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            }
            std::cout<<"\nEnter your amount of deposit: ";
            if(!(std::cin>>amount)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            }
                if(bank.deposit(accountNumber , amount)){
                    std::cout<<"Deposit completed successfully."<<std::endl;
                }
                else{
                    std::cout<<"Failed to deposit."<<std::endl;
                }
            break;
        }    
        case 5:
        {
            int accountNumber{};
            double amount{};
            std::cout<<"Enter your account number: ";
            if(!(std::cin>>accountNumber)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            }
            std::cout<<"\nEnter your amount of withdraw: ";
            if(!(std::cin>>amount)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            }
            if(bank.withdraw(accountNumber, amount)){
                std::cout<<"Withdraw complete successfully."<<std::endl;
            }
            else{
                std::cout<<"Failed to withdraw"<<std::endl;
            }
            break;
        }
        case 6 :
        {   
            int from , to ;
            double amount;
            std::cout<<"Enter your account number:\n";
            if(!(std::cin>>from)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            }
            std::cout<<"\nEnter receiver account number:\n";
            if(!(std::cin>>to)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            }
            std::cout<<"\nEnter amount of money transfer:\n";
            if(!(std::cin>>amount)){
                std::cin.clear();
                std::cin.ignore(10000 , '\n');
                std::cout<<"Invalid input.";
                continue;
            }
            if(bank.transferMoney(from , to , amount)){
                std::cout<<"Transfer complete successfully."<<std::endl;
            }
            else{
                std::cout<<"Failed to transfer money."<<std::endl;
            }

            break;
        }    
        case 0:
        {
            running = false;
            break;
        }    
        default:
        {
            std::cout<<"Invalid choice.\nPlease try again..."<<std::endl;
            break;
        }    
        }
    }

    return 0;
}