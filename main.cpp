#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "Sorting.h"

using namespace std;

int main(int argc, char *argv[]) {

    ifstream file;
    file.open(argv[1]); //file with ints
    setbuf(stdout, NULL);

    if (!file.is_open()) {
        cout << "Error: cannot parse information from ";
        cout << argv[1] << endl;
        exit(0);
    } //if

    int number;
    int size = 10000;
    int num[10000];
    for (int i = 0; file >> number; i++) {
        num[i] = number;
    } //for

    file.close();

    cout << "selection-sort (s)  merge (m)  heap-sort (h)  quick-sort-fp (q)" << endl;
    cout << "quick-sort-rp (r)" << endl;
    cout << "Enter the algorithm: ";
    char sort;
    cin >> sort;
    cout << endl;

    for (int i = 0; i < 10000; i++) {
        cout << num[i] << " ";
    } // for
    cout << endl;
    if (sort == 's') {
        cout << "#Selection-sort comparison: " << Sorting::selectionSort(num, size);
    } // if
    if (sort == 'm') {
        cout << "#Merge-sort comparisons: " << Sorting::mergeSort(num, size);
    } // if
    if (sort == 'h') {
        cout << "#Heap-sort comparisons: " << Sorting::heapSort(num, size);
    } // if
    if (sort == 'q') {
        cout << "#Quick-sort-fp comparisons: " << Sorting::quickSortFP(num, size);
    } // if
    if (sort == 'r') {
        cout << "#Quick-sort-rp comparisons: " << Sorting::quickSortRP(num, size);
    } // if
    else {
        cout << "invalid command" << endl;
    } // else
} //main
