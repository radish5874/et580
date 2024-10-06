#include<iostream>
#include<string>
using namespace std;

class Person{
private:
    string *name;
public:
    Person():name(nullptr){}

    void output(){
        cout << *name <<endl;
    }

    Person(string n):name(new string(n)){}


    ~Person () {
        cout << "==> (Person) destructor called. " << endl;
        delete name;
    }

    Person(const Person &p):name(new string(*(p.name))){
        cout << "==> (Person) copy constructor was called." <<endl;
    }
    
    Person& operator=(const Person &p){
        cout << "==> (Person) Assignment operator was called." << endl;
        if(this != &p){
        delete name;
        name = new string(*(p.name));
        }
        return *this;
    }

};

int main() {
    cout << endl;
    Person *p = new Person("David"); 
    p->output();
    Person p1(*p),p2;
    p1.output();
    p2 = p1;
    p2.output();
    delete p;
    cout << endl;
    return 0;
}