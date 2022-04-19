#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "Sorting.h"
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

    cout << "Size of Input: ";
    int size;
    cin >> size;
    cout << endl;
    if (size < 10) {
        cout << "Invalid size";
        exit(0);
    } // if
    int * num = new int[size];

    for (int i = 0; i < size;i++) {
        num[i] = i;
    }

    for (int i = 0; i < size;i++) {
        srand(time(0) + i);
        int j = rand()%size;
        int t = num[i];
        num[i] = num[j];
        num[j] = t;
    } // for

    cout << "selection-sort (s)  merge (m)  heap-sort (h)  quick-sort-fp (q)" << endl;
    cout << "quick-sort-rp (r)" << endl;
    cout << "Enter the algorithm: ";
    char sort;
    cin >> sort;
    cout << endl;

    /**
    for (int i = 0; i < 10000; i++) {
        cout << num[i] << " ";
    } // for
    cout << endl;
    */

    if (sort == 's') {
        Sorting::selectionSort(num, size);
        cout << "#Selection-sort comparison: " << Sorting::getComparisons() << endl;
        exit(1);
    } // if
    if (sort == 'm') {
        int * arr = Sorting::mergeSort(num, size);
        for (int i = 0; i < size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "#Merge-sort comparisons: " << Sorting::getComparisons() << endl;
        exit(1);
    } // if
    if (sort == 'h') {
        Sorting::heapSort(num, size);
        cout << "#Heap-sort comparisons: " << Sorting::getComparisons() << endl;
        exit(1);
    } // if
    if (sort == 'q') {
        Sorting::quickSortFP(num, 0, 10000);
        cout << "#Quick-sort-fp comparisons: " << Sorting::getComparisons() << endl;
        exit(1);
    } // if
    if (sort == 'r') {
        Sorting::quickSortRP(num, 0, 10000);
        cout << "#Quick-sort-rp comparisons: " << Sorting::getComparisons() << endl;
        exit(1);
    } // if
    else {
        cout << "invalid command" << endl;
        exit(0);
    } // else
} //main
