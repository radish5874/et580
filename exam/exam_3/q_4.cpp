#include <iostream>
#include <vector>
#include <algorithm>
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

double total_balance(vector<BankAccount*>& accounts) {
    double total = 0.0;
    for (auto& acc : accounts) {
        total += acc->displayBalance();
    }
    return total;
}
double max_balance(vector<BankAccount*>& accounts) {
    double max_bal = 0.0;
    for (auto& acc : accounts) {
        if (acc->displayBalance() > max_bal) {
            max_bal = acc->displayBalance();
        }
    }
    return max_bal;
}

double avg_balance(vector<BankAccount*>& accounts) {
    double total = 0.0;
    int count = 0;
    for (auto& acc : accounts) {
        total += acc->displayBalance();
        count++;
    }
    return total / count;
}

int main(){
vector<BankAccount*> a;
a.push_back(new SavingAccount(1050,0.02)); 
a.push_back(new CheckingAccount(4000,50,100)); 
a.push_back(new SavingAccount(2000,0.04)); 
a.push_back(new CheckingAccount(3000,60,200)); 
cout<<total_balance(a)<<endl; 
cout<<max_balance(a)<<endl; 
cout<<avg_balance(a)<<endl;
}

