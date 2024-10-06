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

    friend ostream& operator<<(ostream& os,Point p){
    os << "(" << p.x << "," << p.y << ")";

    return os;
    }
    
    friend istream& operator>>(istream& is,Point &p){
    is>> p.x >> p.y ;
    return is;
    }

};

double distance(Point &a,Point &b){
    return sqrt(pow(b.getX()-a.getX(),2) + pow(b.getY()-a.getY(),2));
}



int main(){
Point a(3,4); 
cout<<a<<endl; // (3,4) 
cout<<"Enter x, y:"; 
cin>>a; cout<<a<<endl;
}