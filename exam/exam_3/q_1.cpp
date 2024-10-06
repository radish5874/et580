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

    void displayBalance(){
        cout << "balance: " << balance << endl;
    }

    double getBalance(){ return balance;}

};



int main(){
    BankAccount a(100); 
    a.displayBalance(); 
    a.deposit(1000.75); 
    a.displayBalance(); 
    a.withdraw(200.50); 
    a.displayBalance(); 
    cout<<a.getBalance()<<endl;
    return 0;

}