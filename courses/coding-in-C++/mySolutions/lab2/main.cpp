#include "bankAccount.hpp"
#include "note.hpp"
#include <iostream>
#include <string>

int main(){

    //--------------- section 1 ----------

    BankAccount myBankAccount;

    myBankAccount.setOwner();
    myBankAccount.deposit(300);
    myBankAccount.getAccountInfo();
    myBankAccount.withdraw(150);
    double balance= myBankAccount.getBalance();
    std::cout<<balance<<std::endl;
    myBankAccount.withdraw(170);

    //-------- section 2 -----------

    Note firstNote("hey there");
    Note secondNote(firstNote);

    firstNote.display();
    secondNote.display();

    //you create a copy of the first note -> copy constructor (but string pointer points to same allocated Memory)
    // => pointer is freed twice -> error

    

    return 0;
}