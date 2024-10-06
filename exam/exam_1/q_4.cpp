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

    friend bool operator==(Point a,Point b){
    return ((a.x == b.x) && (a.y == b.y));
    }

    friend Point operator+(Point a,Point b){
    double x = (a.x + b.x);
    double y = (a.y +b.y);
    return Point(x,y);
    }

    friend Point operator+(Point a,int b){
    double x = a.x + b;
    double y = a.y +b;
    return Point(x,y);
    }

    friend Point operator+=(Point &a,Point b){
    double x = a.x+b.x;
    double y = a.y+b.y;
    a.setX(x);
    a.setY(y);
    return Point(x,y);
    }

    friend Point operator+=(Point &a,int b){
    double x = a.x+b;
    double y = a.y+b;
    a.setX(x);
    a.setY(y);
    return Point(x,y);
    }

    

};

double distance(Point &a,Point &b){
    return sqrt(pow(b.getX()-a.getX(),2) + pow(b.getY()-a.getY(),2));
}



int main(){
Point a(3,4),b(1,2); 
cout<<a+b<<endl; 
cout<<a+10<<endl; 
cout<<a<<endl; // (3,4) 
cout<<b<<endl; // (1,2)
cout<<(a+=b)<<endl; // (4,6) 
cout<<a<<endl; // (4,6) 
cout<<b<<endl; // (1,2)
cout<<(a+=10)<<endl;// (14,16) 
cout<<a<<endl; // (14,16)
}