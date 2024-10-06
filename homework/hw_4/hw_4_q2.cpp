#include <iostream>
using namespace std;

class Person{
private:
    string name;
    int size;
    int capacity;
    string *family;

public:
    Person():name("TBD"),capacity(3),size(0),family(new string[capacity]){}

    Person(string name):name(name),capacity(3),size(0),family(new string[capacity]){}

    Person(string name, int capacity):name(name),capacity(capacity),size(0),family(new string[capacity]){}

    string getName(){return name;}

    void setName(string n){name = n;}

    void grow(){
        cout << "Person => Grow function was called." <<endl;
        int new_capacity = capacity * 2;
        string* new_family = new string[new_capacity];

        for (int i = 0; i < size; i++){
            new_family[i] = family[i];
        }

        delete[] family;
        family = new_family;
        capacity = new_capacity;

    }

    void add(string newMember){
        if (size >= capacity){grow();}
        family[size] = newMember;
        size ++;
    }

    void display(){
        cout<< "Name: " << name << endl
            << "Family: ";
        for(int i = 0; i < size; i++){
            cout << family[i] << " ";
        }
        cout << endl;
    }

    ~Person(){
        cout << "Person => destructor was called." << endl; 
        delete [] family;
    }

    Person& operator=(Person &p){
        cout<< "Person => assignment operator was called." << endl; 
        if(this != &p){
            delete [] family;
            size = p.size;
            capacity = p.capacity;
            family = new string[capacity];

            for(int i = 0; i < size ; i++){
                family [i] = p.family[i];
            }

        }
        return *this;
    }

    Person(Person &p):name(p.name),capacity(p.capacity),size(p.size),family(new string [p.capacity]){
        cout << "Person => copy constructor was called." <<endl;
        for(int i = 0 ;i < size; i++){
            family[i] = p.family[i];
        }
    }
};




int main(){
    cout << endl;

    Person p("Joe");

    p.add("Sarah");
    p.add("John");
    p.add("Nora");
    p.display();

    p.add("Nora");
    cout << endl;

    Person p2 = p;
    p2.setName("Jack");
    p2.add("Sam");
    p2.display();
    cout << endl;

    Person p3;
    p3 = p2;
    p3.setName("Kate");
    p3.add("Tom");
    p3.display();

    cout<<"\n\nfinal result:"<<endl;
    p.display();
    p2.display();
    p3.display();
    cout << endl;
    return 0;
} 