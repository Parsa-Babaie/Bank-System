
#include <iostream>

#include "Bank.h"
void showInfo(){
    std::cout<<"\n===== Bank-System =====\n"<<std::endl;
    std::cout<<"1. Creat Account\n"<<std::endl;
    std::cout<<"2. Show All accounts\n"<<std::endl;
    std::cout<<"3. Show Balance\n"<<std::endl;
    std::cout<<"4. Deposite\n"<<std::endl;
    std::cout<<"5. Withdraw\n"<<std::endl;
    std::cout<<"0. Exit\n"<<std::endl;
}
int main(){
    int choice;
    Bank bank;
    bool running = true;
    while(running){
        showInfo();
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            std::string name;
            double amount;
            std::cout<<"Enter your name: ";
            std::cin>>name;
            std::cout<<"Enter your amount: ";
            std::cin>>amount; 
            if(bank.createAccount(name,amount)){
                std::cout<<"Your Account created successfuly"<<std::endl;
            }
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 0:
            running = false;
            break;
        default:
            std::cout<<"You Enter a Wrong valid of choice.\ntry again..."<<std::endl;
            break;
        }
    }

    return 0;
}