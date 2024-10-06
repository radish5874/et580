#include <iostream>
using namespace std;

void print(int *a,int size){
    for (int i = 0; i < size; i++){
        cout << *(a+i) << " " ;
    }
    cout << endl;
}

void print(int *a,int size,int index){
    if(index>1 && index< size-2){
        cout << a[index-1] << " "
             << a[index] << " "
             << a[index+1];
    }
}

int sum(int *a,int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += *(a+i);
    }
    return sum;
}

int average(int *a, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += *(a+i);
    }
    return sum/size;
}

int main(){
    cout << endl;

    int *a = new int[5] {5,15,25,35,45};
    print(a,5);
    print(a,5,2);
    cout<<endl<<sum(a,5)<<endl;
    cout<<endl<<average(a,5)<<endl;

    cout << endl;
    return 0;
}

