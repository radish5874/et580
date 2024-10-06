#include<iostream>
#include<string>
#include <cassert>
using namespace std;

class Person{
protected:
    string *name;
public:
    Person():name(nullptr){}

    virtual void output(){
        cout << "Name: "<<*name <<endl;
        
    }

    Person(string n):name(new string(n)){
        
    }

    string getName(){
        cout << *name;
        return *name;
    }

    virtual ~Person () {
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

class Student: public Person{
private:
    int *id;

public:

    Student():Person("TBD"),id(nullptr){}

    Student(string n,int i):Person(n){
        assert(i>=1000 && i<=9999);
        id = new int(i);
    }

    virtual void output(){
        cout << "Name: " << *name <<endl
             << "ID: " << *id << endl;
    }

     ~Student(){
        cout << "==> (Student) Destructor was called." << endl;
        delete id;
    }


    Student(Student &s):Person(s), id(new int (*(s.id))){
        cout << "==> (Student) copy constructor was called." << endl;
    }

    Student& operator=(const Student &s){
        if(this != &s){
        Person::operator=(s);
        delete id;
        id = new int(*(s.id));
        }
        return *this;
    }
    void setID(int i){
        assert(i>=1000 && i<=9999);
        *id = i;
    }
};
class Instructor: public Person{
private:
  string department;
public:
  Instructor(): Instructor("TBD","TBD"){}
  Instructor(string n,string d):Person(n),department(d){}
  void output() override {cout<<"Name:"<<*name<<endl<<"Department: "<<department<<endl;}
};

int main() {
   cout << endl;
    Person **a = new Person*[4];
    a[0] = new Student("David",1212); 
    a[1] = new Instructor("Sam","Math"); 
    a[2] = new Student("Tom",2345);
    a[3] = new Instructor("Jack","History");
    for(int i=0; i<4; i++) { a[i]->output(); 
        cout<<endl;
    }
    cout << endl; 
    return 0;
}