#include <iostream>
using namespace std;

class IntArr{
private:
    int capacity;
    int size;
    int *array;
public:
    IntArr():capacity(0),size(0),array(nullptr){}
    IntArr(int capacity):capacity(capacity),size(0),array(new int[capacity]){}
    ~IntArr(){ delete [] array;}

    const int& operator[](int index){
        assert(index >= 0 || index < size);
        return array[index];
    }

    IntArr(IntArr &IA):capacity (IA.capacity),size(IA.size),array(new int [IA.capacity]){
        for(int i = 0 ;i < size; i++){
            array[i] = IA.array[i];
        }
    }

    IntArr& operator=(IntArr &IA){
        if(this != &IA){
            delete [] array;
            size = IA.size;
            capacity = IA.capacity;
            array = new int[capacity];

            for(int i = 0; i < size ; i++){
                array [i] = IA.array[i];
            }

        }
        return *this;
    }

    void grow(){
        int new_capacity = capacity * 2;
        int* new_array = new int[new_capacity];

        for (int i = 0; i < size; i++){
            new_array[i] = array[i];
        }

        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }

    void push_back(int val){
        if(size >= capacity){grow();}
        array[size] = val;
        size ++;
    }


    void pop_back(){
        if(size >= 1){
            size--;
            int *temp = new int[capacity];
            for(int i=0;i<size;i++){
                temp[i] = array[i];
            }
            delete [] array;
            array = temp;
        }else{
            cout<< "can't pop" << endl;
        }
    }

    int getSize(){return size;}

};








int main(){
    cout << endl;

    IntArr a{5};
    for(int i=0; i<5; i++) { a.push_back((i+1)*5); }
    cout << "Array size: " << a.getSize() << endl;

    cout << "Array A: ";
    for(int i=0; i<a.getSize(); i++) {  cout << a[i] << " "; }
    cout << endl << endl;

    a.push_back(30);
    a.push_back(35);
    cout << "Array size: " << a.getSize() << endl;

    IntArr b = a;
    cout << "Array A: ";
    for(int i=0; i<a.getSize(); i++) {  cout << a[i] << " "; }
    cout << "\nPArray B: ";
    for(int i=0; i<b.getSize(); i++) {  cout << b[i] << " "; }
    cout << endl << endl;

    a.pop_back();
    cout << "Array size: " << a.getSize() << endl;
    b = a;
    cout << "Array A: ";
    for(int i=0; i<a.getSize(); i++) {  cout << a[i] << " "; }
    cout << "\nArray B: ";
    for(int i=0; i<b.getSize(); i++) {  cout << b[i] << " "; }
    cout << endl << endl;

    cout << endl;
    return 0;
};
