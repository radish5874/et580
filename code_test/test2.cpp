#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <class T>
set<T> common(vector<T> v[], int size) {
    set<T> result;
    
    if (size == 0)
    
        return result;
        cout<< "nothing";
    
    // Initialize the result set with the elements from the first vector
    for (const auto& element : v[0])
        result.insert(element);
    
    // Iterate over the remaining vectors
    for (int i = 1; i < size; i++) {
        set<T> current;
        
        // Insert the elements of the current vector into a set
        for (const auto& element : v[i])
            current.insert(element);
        
        // Find the intersection between the current set and the result set
        set<T> intersection;
        for (const auto& element : result) {
            if (current.find(element) != current.end())
                intersection.insert(element);
        }
        
        // Update the result set with the intersection
        result = intersection;
    }
    
    return result;
}

int main() {
    vector<int> v[5];
    v[0] = vector<int>{1, 2, 3, 4, 7};
    v[1] = vector<int>{1, 4, 6, 7};
    v[2] = vector<int>{4, 7, 8, 10};
    v[3] = vector<int>{1, 4, 7, 10, 11, 12};
    v[4] = vector<int>{1};
    
    set<int> s = common(v, 5);
    
    for (int i : s)
        cout << i << " ";
    
    return 0;
}
