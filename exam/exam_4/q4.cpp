#include <iostream>
#include <vector>
#include <set>

using namespace std; 


template <class T>
set<T> common(vector<T> v[],int size){
    set<T> common_element;
    if(size == 0){
        cout << "nothing here";
        return common_element;
    }

    set <T> newelement;
    
    for (int i = 0; i < size; i++){
        set<T> current_set(v[i].begin(),v[i].end());
        
        for (auto& element : current_set){
            if(newelement.count(element)==0){
                newelement.insert(element);
            }
        }

        common_element.insert(newelement);
        newelement.clear();
    }
    
    return common_element;

}

int main(){
    vector<int> v[4];
    v[0] = vector<int>{1,2,3,4,7};
    v[1] = vector<int>{1,4,6,7};
    v[2] = vector<int>{4,7,8,10};
    v[3] = vector<int>{1,4,7,10,11,12}; 
    set<int> s = common(v,4);
    for(int i: s) cout<<i<<" ";
    return 0;
}


