#include "Sorting.h"

long Sorting::getComparisons() {
    return comparisons;
} // getComparisons

void Sorting::setComparisons(long num) {
    comparisons = num;
} // setComparisons

void Sorting::selectionSort(int num[], int size) {
    //find lowest value
    //loop to second to last index
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

void Sorting::mergeSort(int num[], int size) {

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
