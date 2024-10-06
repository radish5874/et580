#include<iostream>
using namespace std;

void populate(int* a, int size){
  int n = 0 ;
  for(int i=0;i<size;i++)
    *(a+i) = n++;
}

void print(int *a, int size){
    for (int i = 0; i < size; i++){
        cout<< a[i] << " ";
    }
    cout << endl;
}

void printMemory(int *a, int size){
    for (int i = 0; i < size; i++){
        cout<< &a[i] << endl;
    }
}

int *grow(int *a, int size, int newSize){
    int *temp_a=new int [newSize];

    cout << "Inside grow:" << endl;

    for (int i =0;i < newSize;i++){
        temp_a[i]=a[i];
        cout << *(temp_a+i) << " ";
    }

    cout << endl; 

    for (int i = 0; i < newSize; i++){
        cout<< &temp_a[i] << endl;
    }

    cout << endl; 
    
    delete [] a;
    return temp_a;
}


int main( ) { 
    cout << endl;

    int size, newSize;
    cout << "Enter a size: "; 
    cin >> size;
    cout << endl;

    int *p = new int[size]();
    cout << "Original: " << endl; 
    populate(p, size);
    print(p, size); 
    printMemory(p, size);
    cout << endl;

    cout << "Enter a new size: "; 
    cin >> newSize;
    cout << endl;

    p = grow(p, size, newSize); 
    cout << "After grow: " << endl; 
    print(p, newSize); 
    printMemory(p, newSize);

    cout << endl;
    return 0; 
}