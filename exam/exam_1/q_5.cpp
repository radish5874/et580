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


    
    // 上次不会写
    double& operator[](int index){
        assert(index>=0&&index<=1);
        if(index==0)return x;
        else return y;
    }



    // here not finish, don't know how to change the values
    // at the same time with index.
    
    //set values.




    Point& operator++(){
        x++;
        y++;
    return *this;
    }
    
    Point operator++(int){
        Point temp(x,y);
        x++;
        y++;
        return temp;
    }
};

double distance(Point &a,Point &b){
    return sqrt(pow(b.getX()-a.getX(),2) + pow(b.getY()-a.getY(),2));
}



int main(){
Point a(3,4); cout<<a[0]<<endl; // 3 
cout<<a[1]<<endl; // 4 
a[0]=1;
a[1]=2;
cout<<a<<endl; // (1,2) 
cout<<++a<<endl; // (2,3) 
cout<<a<<endl; // (2,3) 
cout<<a++<<endl; // (2,3) 
cout<<a<<endl; // (3,4)

}