#include <iostream>
using namespace std;

class Vehicle {
private:
    
    int number_of_doors;
    string brand;
public:
    Vehicle(): brand("TBD"), number_of_doors(0){}
    Vehicle(string b, int n): brand(b), number_of_doors(n) {}
    void display(){
        cout<< "Brand: " << brand <<endl
            << "Number of Doors: " << number_of_doors << endl;
    }
};


int main(){
    Vehicle a,b("BMW", 4); 
    a.display();
    b.display();
    
    cout << endl;
    return 0;
}