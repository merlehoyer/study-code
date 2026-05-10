#include <iostream>
#include <string>
#include "bankAccount.hpp"

std::string BankAccount::getOwner()const{
    return owner;
}

void BankAccount::setOwner(){
    std::cout<<" ";
    std::cin>>std::ws;
    std::getline(std::cin,owner);

    return;
}

void BankAccount::deposit(double newMoney){
    if(newMoney<=0){
        std::cout<<"not valid amount, please retry it"<<std::endl;
    }else{
        balance+=newMoney;
    }
    return;
}

void BankAccount::withdraw(double sumMoney){
    if((balance-sumMoney)>=0){
        balance= balance-sumMoney;
    }else{
        std::cout<<"Not enough money in bank account"<<std::endl;
    }
    return;
}

double BankAccount::getBalance()const{
    return balance;
}

void BankAccount::getAccountInfo()const{
    std::cout<<"Name of Owner: "<<owner<<"| Balance: "<<balance;
}



// ohne section IV

//Problem: balance can only be accesed from inisde the class, is a problem if the function getBalance() is defined outside of the class