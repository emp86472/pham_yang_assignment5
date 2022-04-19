#ifndef SORTING_H
#define SORTING_H

class Sorting {

public:
    static int * mergeSort(int num[], int size);
    static void selectionSort(int num[], int size);
    static int * heapSort(int num[], int size);
    static void quickSortFP(int num[], int start, int end);
    static void quickSortRP(int num[], int start, int end);
    static long getComparisons();
    static void resetComparisons();
    //static int * buildMaxHeap(int num[], int size);

private:
    static long comparisons;
    //helpers for mergeSort
    static int * mergeArrays(int Larr[], int l, int Rarr[], int r);

    //helpers for heapSort
    static int * buildMaxHeap(int num[], int size);
    static void reheapDown(int num[], int root, int b);
    static void reheapUp(int num[], int b);
    static void swap(int &a, int &b);
}; //Sorting

#endif
