#include "Sorting.h"
#include <iostream>

using namespace std;

long Sorting::getComparisons() {
    return comparisons;
} // getComparisons

void Sorting::setComparisons(long num) {
    comparisons = num;
} // setComparisons

void Sorting::selectionSort(int num[], int size) {
    //find lowest value
    //loop to second to last index
    comparisons = 0;
    for (int j = 0, i = 0; j < size - 1; j++) {
        int current = num[j];
        int index = j;
        //loop from j + 1 to the last index
        for (i = j + 1; i < size; i++) {
            if (num[i] < current) {
                current = num[i];
                index = i;
            } //if
            comparisons++;
        } //for
        num[index] = num[j];
        num[j] = current;
    } //for
} //selectionSort

int * Sorting::mergeSort(int num[], int size) {
    if (size == 1) {
        return num;
    } //if
    //create 2 subarrays
    int l = size / 2;
    int r = size / 2;
    if (size % 2 != 0) {
        r++;
    } //if
    int *Larr = new int[l];
    int *Rarr = new int[r];

    //fill leftarray
    for (int i = 0; i < l; i++) {
        Larr[i] = num[i];
        //cout << Larr[i];
    } //for
    //cout << endl;

    //fill rightarray
    for (int i = l, j = 0; j < r; i++, j++) {
        Rarr[j] = num[i];
        //cout << Rarr[j];
    } //for
    //cout << endl;

    return mergeArrays(mergeSort(Larr, l), l, mergeSort(Rarr, r), r);
} //mergeSort

void Sorting::heapSort(int num[], int size) {

} //heapSort

void Sorting::quickSortFP(int num[], int start, int end) {
    if (start < end) {
        int part; // partitioning index
        int pivot = num[start]; // pivot
        int i = (start - 1);
        for (int j = start + 1; j <= end; j++) {
            if (num[j] < pivot) {
                i++;
                int t = num[i];
                num[i] = num[j];
                num[j] = t;
            } // if
            comparisons++;
        } // for
         int t = num[i + 1];
         num[i + 1] = num[end];
         num[end] = t;
         part = i + 1;
         quickSortFP(num, start, part - 1);
         quickSortFP(num, part + 1, end);
    } // if
} //quickSortFP

void Sorting::quickSortRP(int num[], int start, int end) {
} //quickSortRP

int * Sorting::mergeArrays(int Larr[], int l, int Rarr[], int r) {
    int *arr = new int[l + r];
    //l&r are the sizes
    //left&right are the indeces
    for (int i = 0, left = 0, right = 0; i < l + r; i++) {

        if (left < l && right < r) {
            if (Larr[left] > Rarr[right]) {
                arr[i] = Rarr[right];
                right++;
            } else {
                arr[i] = Larr[left];
                left++;
            } //if
        } else if (left >= l && right < r) {
            arr[i] = Rarr[right];
            right++;
        } else if (right >= r && left < l) {
            arr[i] = Larr[left];
            left++;
        } //if
    } //for
    return arr;
} //mergeArrays
