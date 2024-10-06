#include<iostream>
using namespace std;

class RatNum{
private:
    int numerator, denominator;
public:
    //1) default constructor
    RatNum():RatNum(0,0){}      
    
    //2) single parameter constructor to create numerator/1
    RatNum(int n):RatNum(n,1) {} 
    
    //3) dual parameter constructor to create numerator/denominator
    RatNum(int n,int d):numerator(n),denominator(d) {} 

    //set nuerator and denominator
    void setNum(int n){numerator = n;}
    void setDen(int d){denominator = d;}
    
    //get nuerator and denominator
    int getNum(){return numerator;}
    int getDen(){return denominator;}


    static int gcd(int a, int b){
        if (a%b == 0){
            return b;
        }
        return gcd(b,a%b);
    }

    static int lcm(int a, int b){
        return (a*b)/gcd(a,b);
    }

    void reduce(){
        int gcdn = gcd (numerator,denominator);
        setNum(numerator / gcdn);
        setDen(denominator/ gcdn);

    }
};

int main() {
    cout << endl;
// test constructors, accessors, mutators
    cout << "Default Constructor: ";
    RatNum r1;
    cout << r1.getNum() << "/" << r1.getDen() << endl; 
    cout << "Single Parameter Constructor: ";
    RatNum r2(2);
    cout << r2.getNum() << "/" << r2.getDen() << endl; 
    cout << "Dual Parameter Constructor: ";
    RatNum r3(1,3);
    cout << r3.getNum() << "/" << r3.getDen() << endl; 
    cout << "Accessors / Mutators: ";
    r3.setNum(3);
    r3.setDen(12);
    cout << r3.getNum() << "/" << r3.getDen() << endl;
    // test gcd
    cout << "\nGCD of the last fraction: "
    << RatNum::gcd(r3.getNum(),r3.getDen()) << endl;
    cout << "GCD of 40 and 24: " << RatNum::gcd(40,24) << endl;
    // test lcm
    cout << "\nLCM of the last fraction: "
    << RatNum::lcm(r3.getNum(),r3.getDen()) << endl; 
    cout << "LCM of 3 and 5: " << RatNum::lcm(3,5) << endl;
    // test reduce
    cout << "\nReducing the last fraction: "; r3.reduce();
    cout << r3.getNum() << "/" << r3.getDen() << endl;
    cout << endl;
    return 0; }

