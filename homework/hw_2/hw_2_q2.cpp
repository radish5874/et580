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
        setDen(denominator / gcdn);
    }
    //a.
    RatNum operator+(){
        return RatNum(+numerator,denominator);
    }
    //b.
    RatNum operator-(){
        return RatNum(-numerator,denominator);
    }

    friend RatNum operator+(RatNum a, RatNum b){
        int lcmn = lcm(a.denominator,b.denominator);
        RatNum x;
        x.setNum((a.numerator*(lcmn/a.denominator))+(b.numerator*(lcmn/b.denominator)));
        x.setDen(lcmn);
        x.reduce();
        return x;
    }

    friend RatNum operator-(RatNum a, RatNum b){
        int lcmn = lcm(a.denominator,b.denominator);
        RatNum x;
        x.setNum((a.numerator*(lcmn/a.denominator))-(b.numerator*(lcmn/b.denominator)));
        x.setDen(lcmn);
        x.reduce();
        return x;
    }

    friend RatNum operator*(RatNum a, RatNum b){
        RatNum x;
        x.setNum(a.numerator * b.numerator);
        x.setDen(a.denominator * b.denominator);
        x.reduce();
        return x;
    }

    friend RatNum operator/(RatNum a, RatNum b){
        RatNum x;
        x.setNum(a.numerator * b.denominator);
        x.setDen(a.denominator * b.numerator);
        x.reduce();
        return x;
    }

    friend bool operator==(RatNum a, RatNum b){
        RatNum a1 = a;
        RatNum b1 = b;
        a1.reduce();
        b1.reduce();
        if (a1.numerator == b1.numerator && a1.denominator == b1.denominator){
            return 1;
        }else{
            return 0;
        }
    }

    friend bool operator!=(RatNum a, RatNum b){
        RatNum a1 = a;
        RatNum b1 = b;
        a1.reduce();
        b1.reduce();
        if (a1.numerator == b1.numerator && a1.denominator == b1.denominator){
            return 0;
        }else{
            return 1;
        }
    }

    friend bool operator>(RatNum a, RatNum b){
        int lcmn = lcm(a.denominator,b.denominator);
        if ((a.numerator * (lcmn / a.denominator)) > (b.numerator * (lcmn / b.denominator))){
            return 1;
        }else{
            return 0;
        }
    }

    friend bool operator>=(RatNum a, RatNum b){
        int lcmn = lcm(a.denominator,b.denominator);
        if ((a.numerator * (lcmn / a.denominator)) >= (b.numerator * (lcmn / b.denominator))){
            return 1;
        }else{
            return 0;
        }
    }

    friend bool operator<(RatNum a, RatNum b){
        int lcmn = lcm(a.denominator,b.denominator);
        if ((a.numerator * (lcmn / a.denominator)) < (b.numerator * (lcmn / b.denominator))){
            return 1;
        }else{
            return 0;
        }
    }

    friend bool operator<=(RatNum a, RatNum b){
        int lcmn = lcm(a.denominator,b.denominator);
        if ((a.numerator * (lcmn / a.denominator)) <= (b.numerator * (lcmn / b.denominator))){
            return 1;
        }else{
            return 0;
        }
    }

    friend ostream& operator<<(ostream& os,RatNum R){
    os << R.numerator << "/" << R.denominator;
    return os;
    }
    
    friend istream& operator>>(istream& is,RatNum &R){
    is>> R.numerator >> R.denominator;
    return is;
    }

    int& operator[](int index){
    assert(index >= 1 && index <= 2);
    if(index == 1) return numerator;
    else return denominator;
    }


};




int main() {
    cout << endl;
    RatNum r1(1,2), r2(1,6), r3(2,5);
    // test operator overloads
    cout << "\nInput/Output Stream Operators: " << endl; 
    RatNum r4;
    cout << "Enter a rational number: ";
    cin >> r4;
    RatNum r10 = r4;
    cout << r4 << endl;
    cout << "Negation Operation: " << endl;
    cout << -r4 << endl;
    // test arithmetic overloads
    cout << "\nArithmetic Operators: " << endl; 
    RatNum r5 = r1 + r2; 
    cout<<r1<<"+"<<r2<< "="<<r5<<endl; 
    RatNum r6 = r1 - r2; 
    cout<<r1<<"-"<<r2<< "="<<r6<<endl; 
    RatNum r7 = r1 * r2; 
    cout<<r1<<"*"<<r2<< "="<<r7<<endl; 
    RatNum r8 = r1 / r2;
    cout<<r1<<"/"<<r2<< "="<<r8<<endl;
    // test arithmetic operation chaining
    cout << "\nArithmetic Chaining: " << endl;
    RatNum r9 = r5 + r6 - r7 * r8;
    cout<<r5<< "+"<<r6<<"-"<<r7<<"*"<<r8<<"="<<r9<<endl;
    // test relational operator overload
    cout << "\nRelational Operators: " << endl;
    cout << r5 << " == " << r6 << "? " << (r5==r6) << endl; 
    cout << r5 << " != " << r6 << "? " << (r5!=r6) << endl; 
    cout << r5 << " > " << r6 << "? " << (r5>r6) << endl; 
    cout << r5 << " < " << r6 << "? " << (r5<r6) << endl;
    // test subscript overload
    cout << "\nSubscript Operator: " << endl;
    cout << r5 << " num=" << r5[1] << " den=" << r5[2] << endl; 
    cout << endl;
    


    return 0;
}

