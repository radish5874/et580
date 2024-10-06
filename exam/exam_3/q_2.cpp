#include <iostream>
using namespace std;

class BankAccount{
private:
    double balance;
public:
    BankAccount():balance(0.0){}
    BankAccount(double bal):balance(bal){}

    void deposit(double amount){
        balance += amount;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
        }else {
            cout << "don't have enough balance.";
        }
    }

    double displayBalance(){
        cout << "balance: " << balance << endl;
        return balance;
    }

    double getBalance(){ return balance;}

};


class SavingAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingAccount():BankAccount(0),interestRate(0){}
    SavingAccount(double init_balance, double init_rate):BankAccount(init_balance),interestRate(init_rate){}

    void addInterest(){
        double interest = getBalance() * interestRate;
        deposit(interest);
    }
    
    void withdraw(double amount){
        double fee = 20;
      
        
        if(getBalance() >= (fee+amount)){
            
            BankAccount:: withdraw(amount +fee);
        } else {
            cout << "Can not withdraw, balance can not be negative." << endl;
        }
    
    }


    double displayBalance(){
        cout << "Saving balance: " << getBalance() << endl
             << "InterstRate: " << interestRate << endl;
        return getBalance();
    }

};



int main(){
    SavingAccount a(19768,0.04); 
    a.displayBalance(); 
    a.addInterest(); 
    a.displayBalance(); 
    a.deposit(7500); 
    a.displayBalance(); 
    a.withdraw(200.50); 
    a.displayBalance(); 
    a.withdraw(50000); 
    a.displayBalance();
    return 0;

}