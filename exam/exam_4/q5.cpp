#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std; 


template <class T>
set<T> second(vector<T> v){
    map <T,int> count;

    for(T& element : v){
        count[element]++;
    }

    int max_count = 0;
    
    for(auto& element : count){
        if (element.second > max_count){
            max_count = element.second;
        }
    }

    int second_max_count = 0;

    for(auto& element : count){
        if (element.second < max_count && element.second > second_max_count){
            second_max_count = element.second;
        }
    }

    set<T> second_max_count_set;
    
    for(auto& element : count){
        if (element.second == second_max_count){
            second_max_count_set.insert(element.first);
        }
    }

    return second_max_count_set;

}

int main() {
    vector<char> v1 {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};
    set<char> result1 = second(v1);
    for (auto& element : result1) {
        cout << element << " ";
    }
    cout << endl;

    vector<int> v2 {1, 2, 3, 1, 2, 3};
    set<int> result2 = second(v2);
    for (auto& element : result2) {
        cout << element << " ";
    }
    cout << endl;

    vector<double> v3 {1.0, 1.0, 2.0, 2.0, 2.0, 3.0, 3.0};
    set<double> result3 = second(v3);
    for (auto& element : result3) {
        cout << element << " ";
    }
    cout << endl;

    return 0;

}