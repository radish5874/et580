#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    const int capacity = 26;
    char teamName[capacity]{};

    int length = input.length();
    int size = 0;
    bool in_the_array = false;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < size; j++) {
            if (teamName[j] == input[i]) {
                in_the_array = true;
                break; // Exit the inner loop if the character already exists
            }
        }

        if (!in_the_array) {
            teamName[size] = input[i];
            size++;
        }

        in_the_array = false;
    }
    cout << size << length;
    if((length % size) == 0){
        cout << "1";
    }else{
        cout << "0";
    }

    for (int x = 0; x < size; x++) {
        cout << teamName[x] << " ";
    }
    cout << endl;
    
    return 0;
}

//asdasdsaaaa 0 
//asdasdaassdd





