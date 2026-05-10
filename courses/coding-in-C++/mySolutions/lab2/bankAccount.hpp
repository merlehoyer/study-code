#include <iostream>
#include <string>

class BankAccount {
    private:
        std::string owner;
        double balance;
    
    public:
        std::string getOwner()const;
        void setOwner();
        void deposit(double newMoney);
        void withdraw(double sumMoney);
        double getBalance()const;
        void getAccountInfo()const;    
};

