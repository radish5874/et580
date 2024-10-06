#include <iostream>
using namespace std;

class BankAccount{
protected:
    double balance;
public:
    BankAccount():balance(0.0){}
    BankAccount(double bal):balance(bal){}

    virtual void deposit(double amount){
        balance += amount;
    }

    virtual void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
        }else {
            cout << "Can not withdraw, balance can not be negative." << endl;
        }
    }

    virtual double displayBalance(){
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
        balance += balance * interestRate;
    }
    
    void withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
        }
        else {
            cout << "Can not withdraw, balance can not be negative." << endl;
        }
    }


    double displayBalance(){
        cout << "Saving balance: " << getBalance() << endl
             << "InterstRate: " << interestRate << endl;
        return getBalance();
    }

};

class CheckingAccount : public BankAccount{

private:
    double Fee ,min_balance;
public:
    CheckingAccount(): BankAccount(100), Fee(20), min_balance(100){}
    CheckingAccount(double bal, double fee, double min_bal): BankAccount(bal), Fee(fee), min_balance(min_bal){}
    
    
    void withdraw(double amount) {
        if (balance - amount >= min_balance) {
            balance -= amount;
        }
        else {
            balance =balance -amount - Fee;
        }
    
    }
    
    double displayBalance(){
        cout << "Checking balance: " << getBalance() << endl;
        return getBalance();
    }

};




int main(){
    BankAccount *a;
    a = new CheckingAccount(3000,50,1500); 
    a->displayBalance();
    a->withdraw(2000);
    a->displayBalance();
    a->withdraw(2000);
    a->displayBalance();
    delete a;
    a = new SavingAccount(1500,0.01); 
    a->displayBalance();
    a->withdraw(1000);
    a->displayBalance();
    a->withdraw(1000);
    a->displayBalance();

}