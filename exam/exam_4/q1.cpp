#include <iostream>
using namespace std; 

template <typename T> 
class Node {
public:
    T data;
    Node<T> *next;
    Node(const T &d): data(d), next(nullptr) {}
};

template <typename T> 
class LList {
private:
    Node<T> *first; 
    Node<T> *last; 
    int size;
public:
    LList(): first(nullptr), last(nullptr), size(0) {} 
    bool empty(){return first == nullptr;}
    int getSize() const{return size;}
    void append(T n){
        Node<T> *temp = new Node<T>(n);
        if (empty()) {
            first = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
        
        size++;
    }
    

    void remove(){
        if(first == nullptr){
            cout << "List is empty.";
            return;
        }
        if(first == last){
            delete first;                            // delete node
            first = last = nullptr;  
            size = 0;                // point first and last to nullptr (empty list)
            return;               
        }
        Node<T> *prev = first;                          // point prev to first node
        Node<T> *current = first->next;                 // point current to second node
        while(current->next != nullptr) {           // traverse until current is last node, prev is second to last node
            prev = prev->next;                      // advance prev
            current = current->next;                // advance current
        }
        prev->next = nullptr;                       // point second to last node to nullptr
        last = prev;                                // point last to new last node
        delete current;                             // delete the original last node
        --size; 
    }
    void printList(){
        Node<T> *current = first;                       // create a node, point it to first
        while(current != nullptr) {                 // repeat until we reach the end of list
            cout << current->data << " ";      // printList the content of the current node
            current = current->next;                // move current to point to the next node in the list
        }
        cout << endl;
    }
};

int main() {
    LList<int> list; 
    list.append(700); 
    list.append(900); 
    list.append(1100); 
    list.append(1200); 
    list.printList(); 
    list.remove(); 
    list.remove(); 
    list.printList();
}
