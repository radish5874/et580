#include <iostream>
#include <cmath>
using namespace std;

bool queensAreSafe(int a[]){
    for(int row = 0; row < 8; row++){                   // run though all the number array. 
        for(int column = row+1; column < 8; column ++ ){ // this loop is for the rest of the coordinates
            // the initialization row+1 is because i don't want the match run duplicate.
            if (a[column]==a[row]|| abs(row-column)==abs(a[row]-a[column])){
            //a[column]==a[row] if is 1, mean they are has the same y values.
            //abs(row-column)==abs(a[row]-a[column]) if is 1, mean they are in the same diagonal.
            // for example (0,1) and (5,6), abs(0-5) ==5 , abs(1-6) ==5 than means they are in the same diagonal.
            // we don't have to check row(Horizontal way) because the program will distribution each number to each line.
                return 0;
            }
        }
    }
    return 1;
}

//the global variable for the size of the chessboard.
const int boardsize =8;

int main(){
    int arr_of_the_num[boardsize];
    cout<< "Enter 8 column values: ";
    for (int y=0;y<8;y++){ 
        cin >> arr_of_the_num[y];// to get the num from console in to the array.
        for (int x = 0; x<8; x++){
            //below is the output part .
            if(x == arr_of_the_num[y]){
                cout << "Q ";
            }else{
                cout << ". ";
            }

        }
        cout << endl;
    }

    cout << endl;
    if (queensAreSafe(arr_of_the_num)){
        cout << "Queens are safe!";
    }else{
        cout << "Queens are not safe!";
    }
    return 0;

}
// 3 6 2 7 1 4 0 5 (safe)

/*
x   y
row arr_of_the_num[row]
0   3
1   6
2   2
3   7
4   1
5   4
6   0
7   5
*/