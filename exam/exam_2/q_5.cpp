#include <iostream>
using namespace std;


void bargraph(int n){
    int count = 0;
    int maxnum = 9;

    int **array = new int*[maxnum];
    for(int i=0;i<maxnum;i++){
        array[i] = new int[maxnum];
    }

    while (n > 0){
        n/=10;
        count++;
    }
    cout << "here";
    cout <<count;

    int *numa = new int[count];
        for(int i=count;i>0;i--){
            *(numa+i) = n%=10;
        }

    for(int i=0;i<maxnum;i++)
        for(int j=0;j<count;j++)
            for(int k=0;k<maxnum;i++){
                if (maxnum - i - *(numa+k)<= 0){
                    *(*(array+i)+j) = 1;
                }else{
                    *(*(array+i)+j) = 0;
                }
            }
    

    for(int i=0;i<maxnum;i++){
        for(int j=0;j<count;j++){
            if (*(*(array+i)+j)== 1){
                cout<< "x";

            }else{
                cout<< " ";
            }
            
        }
    cout<<endl;
  }

    


}

int main(){ 
    bargraph(12945); 
    bargraph(6789102);
}
