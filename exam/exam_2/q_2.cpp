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
};




int main(){
    Wallet a(2),b;
    a[0] = 0.25;
    a[1] = 1;
    a.output();
    a.add(20);
    a.add(10);
    a.output(); 
    cout<<a.total()<<endl; 
    for(int i=0;i<6;i++)
        a.spend(); 
    a.output();
}