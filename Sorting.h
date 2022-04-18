#ifndef SORTING_H
#define SORTING_H

class Sorting {

public:
    static void selectionSort(int num[], int size);
    static void mergeSort(int num[], int size);
    static void heapSort(int num[], int size);
    static void quickSortFP(int num[], int start, int end);
    static void quickSortRP(int num[], int start, int end);
    static long getComparisons();
    static void setComparisons(long num);
private:
    static long comparisons;

}; //Sorting

#endif
