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
};




int main(){
    Wallet a(5),b;
    for(int i=0;i<a.getSize();i++)
        a[i] = i*1.5;
    for(int i=0;i<a.getSize();i++)
        cout<<a[i]<<endl; 
        cout<<endl;
}