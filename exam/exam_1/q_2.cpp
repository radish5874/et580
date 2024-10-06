#include<iostream>
#include<cmath>
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

    Point(double enter_x,double enter_y):x(enter_x),y(enter_y){}

    Point():Point(0,0){}
};

double distance(Point &a,Point &b){
    return sqrt(pow(b.getX()-a.getX(),2) + pow(b.getY()-a.getY(),2));
}

int main(){
Point a(3,4),b; 
cout<<distance(a,b)<<endl; // 5 
Point c(3,0),d(0,4); 
cout<<distance(c,d)<<endl; // 5
}