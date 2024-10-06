#include<iostream>
using namespace std;

class Point{
private:
    double x;
    double y;
public:
    void setX(double enter_x){x=enter_x;}
    void setY(double enter_y){y=enter_y;}

    double getX(){return x;}
    double getY(){return y;}

    void output(){
        cout << "X:" <<x<<" Y:" << y;
    }

};


int main(){
Point a;
a.setX(1.5); 
a.setY(2.5); 
cout<<a.getX()<<endl; 
cout<<a.getY()<<endl; 
a.output();
}