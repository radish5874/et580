#include <iostream>
using namespace std; 
/*

If an array of Integer contains the following elements, 
what would the array look like after the every pass of bubble sort, 
insertion sort, selectionSort, 
Merge sort and Quick sort sorting from low to high?

99 44 55 2 24 9
Answer:
Bubble sort: 
    99 44 55 2 24 9
    44 55 2 24 9 99
    44 2 24 9 55 99
    2 24 9 44 55 99
    2 9 24 44 55 99 

Insertion sort: 
    99 44 55 2 24 9
    44 99 55 2 24 9
    44 55 99 2 24 9
    2 44 55 99 24 9
    2 24 44 55 99 9
    2 9 24 44 55 99

Selection sort: 
    99 44 55 2 24 9
    |2| 99 44 55 24 9
    2 |9| 99 44 55 24
    2 9 |24| 99 44 55
    2 9 24 |44| 99 55
    2 9 24 44 |55| 99
    2 9 24 44 55 99

Merge sort: 
    99 44 55 2 24 9
    99 44 55 | 2 24 9
    99 | 44 55 | 2 | 24 9
    99 | 44 | 55 | 2 | 24 | 9
    44 99 | 2 55 | 9 24
    2 44 55 99 | 9 24
    2 9 24 44 55 99
Quick sort:
    99 44 55 2 24 9
    2 |9| 99 44 55 24 
    2 9 |24| 99 44 55
    2 9 24 |55| 99 44
    2 9 24 |44| 55 99
    2 9 24 44 55 99

*/
