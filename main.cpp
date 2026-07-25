
#include <iostream>

#include "Bank.h"

int main(){
  /*  Account account("Parsa" , 1000);
    std::cout<<"your Balance is: "<<account.getBalance()<<std::endl;
    if(account.deposit(2000)){
        std::cout<<"deposite Successfully done."<<std::endl;
    }
    else std::cout<<"ERROR."<<std::endl;
    std::cout<<"Your new balance is: "<<account.getBalance()<<std::endl;
    if(account.withdraw(200)){
        std::cout<<"withdraw Successfully done."<<std::endl;
    }
    else std::cout<<"ERROR."<<std::endl;
    std::cout<<"Your new balance is: "<<account.getBalance()<<std::endl;
*/
    Bank bank;
    bank.createAccount("Parsa",1000);
    Account* account = bank.findAccount(1001);
    if(account){
        account->deposit(200);
        std::cout<<"your balance is: "<<account->getBalance()<<std::endl;
    }
    else{
        std::cout<<"Account not found!"<<std::endl;
    }

    return 0;
}