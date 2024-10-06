#include<iostream>
#include <cassert>
using namespace std;

template<class T>

class MyArray{
private:
    T   *my_array;
    int size;
    int capacity;

public:
    MyArray():size(0),capacity(0),my_array(nullptr){}

    MyArray(int cap){
        assert (cap >0);
        capacity = cap;
        my_array = new T[capacity];
    }

    ~MyArray(){delete []my_array;}

    MyArray(const MyArray &a):size(a.size),capacity(a.capacity),my_array(new T [a.capacity]){
        for(int i = 0 ;i < size; i++){
            my_array[i] = a.my_array[i];
        }
    }

    MyArray& operator=(const MyArray &a){
        if (this != &a){
            delete [] my_array;
            size = a.size;
            capacity = a.capacity;
            my_array = new T [a.capacity];

            for(int i = 0 ;i < size; i++){
                my_array[i] = a.my_array[i];
            }
        }
        return *this;
    }

    void grow(){
        T *new_array = new T[capacity*2];
        for(int i = 0 ;i < size; i++){
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

    int getSize()const{return size;}

    T& operator[](int index)const{
        assert( index>=0 && index < size);
        return my_array[index];

    }

    void output()const{
        for(int i=0;i<size;i++){
            cout << my_array[i] << " ";
        }
    }
};

int main() {
    
    cout << endl;
    MyArray<int> a(2);
    for (int i = 0; i < 20; i++) {
        a.add(i+1);
    }
    a.output();
    cout << endl;
    MyArray<char> c(20);
    for (int i = 0; i < 26; i++) {
        c.add(static_cast<char>(i+65));
    }
    c.output();
    
    cout << endl;
    return 0;
}