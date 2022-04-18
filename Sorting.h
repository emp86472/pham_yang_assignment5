#ifndef SORTING_H
#define SORTING_H

class Sorting {

public:
    static long selectionSort(int num[], int size);
    static int * mergeSort(int num[], int size);
    static long heapSort(int num[], int size);
    static long quickSortFP(int num[], int size);
    static long quickSortRP(int num[], int size);
    static int * mergeArrays(int Larr[], int l, int Rarr[], int r);

private:
    static long comparisons;
}; //Sorting

#endif
