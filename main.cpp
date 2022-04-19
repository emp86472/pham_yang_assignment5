#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "Sorting.h"

using namespace std;

void printArray(int num[], int size) {
    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    } //for
    cout << endl;
} //printArray

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

    if (sort == 's') {
        Sorting::selectionSort(num, size);
        printArray(num, size);
        cout << "#Selection-sort comparison: " << Sorting::getComparisons() << endl;
        exit(1);
    } // if
    if (sort == 'm') {
        int * arr = Sorting::mergeSort(num, size);
        printArray(arr, size);
        cout << "#Merge-sort comparisons: " << Sorting::getComparisons() << endl;
        exit(1);
    } // if
    if (sort == 'h') {
        int * arr = Sorting::heapSort(num, size);
        printArray(arr, size);
        cout << "#Heap-sort comparisons: " << Sorting::getComparisons() << endl;
        exit(1);
    } // if
    if (sort == 'q') {
        Sorting::quickSortFP(num, 0, size - 1);
        cout << "#Quick-sort-fp comparisons: " << Sorting::getComparisons() << endl;
        printArray(num, size);
        exit(1);
    } // if
    if (sort == 'r') {
        Sorting::quickSortRP(num, 0, size - 1);
        cout << "#Quick-sort-rp comparisons: " << Sorting::getComparisons() << endl;
        printArray(num, size);
        exit(1);
    } // if
    else {
        cout << "invalid command" << endl;
        exit(0);
    } // else
} //main
