#include <iostream>
#include <cassert>
using namespace std;


int** create2DArray(int row, int column){
    int **array = new int*[row];
    for(int i=0;i<row;i++){
        array[i] = new int[row];
    }
    return array;
}

void populate(int** array, int row, int column, int start){
  int n = start;
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      *(*(array+i)+j) = n++;
}

void print(int** array, int row, int column){
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      cout<<*(*(array+i)+j)<<" ";
    }
    cout<<endl;
  }

}

void delete2DArray(int** array, int row, int column){
    for(int i=0;i<row;i++)
        delete [] array[i];
    delete [] array;

}
int main(){
    int **a = create2DArray(3,5); 
    populate(a,3,5,10); 
    print(a,3,5); 
    delete2DArray(a,3,5); 
    cout<<endl;
    a = create2DArray(2,6); 
    populate(a,2,6,22); 
    print(a,2,6); 
    delete2DArray(a,2,6);
}

