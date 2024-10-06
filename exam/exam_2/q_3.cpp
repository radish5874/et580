#include <iostream>
#include <cassert>
using namespace std;

class Wallet{

private:
    double *moneyList;
    int size;
public:
    Wallet():size(0),moneyList(nullptr){}
    Wallet(int s):size(s),moneyList(new double[size]){}
    int getSize(){return size;}
    double& operator[](int index){
        assert(index>=0 && index<size);
        return moneyList[index];
    }

    void add(double m){
        double *tempL = new double [size +1];
        for(int i =0; i < size; i++){
            tempL[i] = moneyList[i];
        }
        tempL[size] = m;
        delete [] moneyList;
        moneyList = tempL;
        size++;
    }

    void spend(){
        if (size ==0){
            cout<< "No more money to spend."<<endl;
        }else{
        double *tempL = new double [size -1];
        for(int i =0; i < size-1; i++){
            tempL[i] = moneyList[i];
        }
        delete [] moneyList;
        moneyList = tempL;
        size--;}
        
    }

    double total(){
        double total = 0.0;
        for (int i = 0; i < size; i++){
            total += moneyList[i];
        }
        
        return total;
    }

    void output(){
        cout << "Money in wallet: " << endl;
        for (int i = 0; i < size; i++){
            cout << "$" << moneyList[i] << endl;
        } 
        cout << "Total: " << "$" <<total()<<endl;

    }
    ~Wallet(){
        cout << "==> Destructor is called" << endl;
        delete [] moneyList;
    }

    Wallet& operator=(Wallet &a){
        cout << "==> Assignment operator is called" << endl;
    if(this != &a){
      if(size != a.size){
        delete [] moneyList;
        moneyList = new double[a.size];
        size = a.size;
      }
      size = a.size;
      for(int i=0;i<size;i++)
        moneyList[i] = a.moneyList[i];
    }
        return *this;
    }

    Wallet(Wallet &a){
        cout << "==> Copy constructor is called" <<endl;
    size = a.size;
    moneyList = new double[size];
    for(int i=0;i<size;i++)
      moneyList[i] = a.moneyList[i];
    }
};




int main(){
    Wallet a(2),c; 
    a[0] = 0.25; 
    a[1] = 1; 
    Wallet b = a; 
    a.add(20); 
    a.output(); 
    b.output();
    c = a; 
    a.add(30); 
    a.output(); 
    c.output();
}