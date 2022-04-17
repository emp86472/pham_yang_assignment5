#include "Sorting.h"

long Sorting::selectionSort(int num[], int size) {
    //find lowest value
    long comparisons = 0;
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
    return comparisons;
} //selectionSort

long Sorting::mergeSort(int num[], int size) {
    return 0;
} //mergeSort

long Sorting::heapSort(int num[], int size) {
    return 0;
} //heapSort

long Sorting::quickSortFP(int num[], int size) {
    return 0;
} //quickSortFP

long Sorting::quickSortRP(int num[], int size) {
    return 0;
} //quickSortRP
