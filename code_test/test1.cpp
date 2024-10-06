#include<iostream>
#include <cassert>
using namespace std;

class SomeObj {
private:
    int id;
public:
    SomeObj():id(0){}
    SomeObj(int i):id(i){}

    void output() const {
        cout << id << " ";
    }

};

template<class T>
class MyArray {
private:
    T *my_array;
    int size;
    int capacity;

public:
    MyArray(): size(0), capacity(0), my_array(nullptr){}

    MyArray(int cap){
        assert (cap >0);
        capacity = cap;
        my_array = new T[capacity];
    }

    ~MyArray(){
        delete [] my_array;
    }

    MyArray(const MyArray &a): size(a.size), capacity(a.capacity), my_array(new T[a.capacity]){
        for(int i = 0 ; i < size; i++){
            my_array[i] = a.my_array[i];
        }
    }

    MyArray& operator=(const MyArray &a){
        if (this != &a){
            delete [] my_array;
            size = a.size;
            capacity = a.capacity;
            my_array = new T[a.capacity];

            for(int i = 0 ; i < size; i++){
                my_array[i] = a.my_array[i];
            }
        }
        return *this;
    }

    void grow(){
        T *new_array = new T[capacity*2];
        for(int i = 0 ; i < size; i++){
            new_array[i] = my_array[i];
        }
        capacity *= 2;
        delete [] my_array;
        my_array = new_array;
    }

    void add(T value){
        if (size >= capacity){
            grow();
        }
        my_array[size] = value;
        size ++;
    }

    int getSize() const {
        return size;
    }

    T& operator[](int index) const {
        assert(index >= 0 && index < size);
        return my_array[index];
    }

    void output() const {
        for(int i=0; i<size; i++){
            my_array[i].output();
        }
    }
};

int main() {
    cout << endl;
    MyArray<SomeObj> a(1);
    SomeObj o1(1);
    SomeObj o2(2);
    SomeObj o3(3);
    SomeObj o4(4);
    SomeObj o5(5);
    SomeObj o6(6);
    SomeObj o7(7);
    SomeObj o8(8);
    SomeObj o9(9);
    SomeObj o10(10);
    a.add(o1);
    a.add(o2);
    a.add(o3);
    a.add(o4);
    a.add(o5);
    a.add(o6);
    a.add(o7);
    a.add(o8);
    a.add(o9);
    a.add(o10);
    a.output();
    cout << endl;
    return 0;
}
