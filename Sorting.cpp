#include "Sorting.h"
#include <iostream>

using namespace std;

long Sorting::comparisons = 0;

/**
 * Returns the number of comparisons.
 * Use after calling the sorting algorithm.
 */
long Sorting::getComparisons() {
    return comparisons;
} // getComparisons

/**
 * Must be called after every sorting algorithm.
 */
void Sorting::resetComparisons() {
    comparisons = 0;
} // setComparisons

/**
 * Sorts the array passed by reference.
 */
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

/**
 * Returns a pointer to a new sorted array
 */
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

int * Sorting::heapSort(int num[], int size) {
    int * maxHeap = buildMaxHeap(num, size);

    for (int b = size - 1; b > 0; b--) {
        //swap root and bottom
        int temp = maxHeap[0];
        maxHeap[0] = maxHeap[b];
        maxHeap[b] = temp;

        reheapDown(maxHeap, 0, b - 1);
    } //for
    return maxHeap;
} //heapSort

void Sorting::quickSortFP(int num[], int start, int end) {
    if (start >= end) {
        return;
    } //if
    if (start - end == 1) {
        if (num[start] > num[end]) {
            swap(num[start], num[end]);
        } //if
        comparisons++;
        return;
    } //if
    int p = start; //pivot
    bool fl = false; //found left
    bool fr = false;
    int r = end;
    int l = start + 1;
    for (int la = 1, ra = 1; l <= r; l += la, r -= ra) {
        if (!fl && num[l] > num[p]) {
            la = 0; //left add
            fl = true;
        } //if
        if (!fr && num[r] < num[p]) {
            ra = 0; //right add
            fr = true;
        } //if
        comparisons += 2;
        if (fl && fr) {
            swap(num[l], num[r]);
            fl = false;
            fr = false;
            la = 1;
            ra = 1;
        } //if
    } //for
    swap(num[p], num[r]);
    quickSortFP(num, start, r - 1);
    quickSortFP(num, r + 1, end);
} //quickSortFP

void Sorting::quickSortRP(int num[], int start, int end) {
    if (start >= end) {
        return;
    } //if
    if (start - end == 1) {
        if (num[start] > num[end]) {
            swap(num[start], num[end]);
        } //if
        comparisons++;
        return;
    } //if

    int range = end - start;
    srand(time(0));
    int random = rand() % range + start;

    int p = start; //pivot
    swap(num[p], num[random]);
    bool fl = false; //found left
    bool fr = false;
    int r = end;
    int l = start + 1;
    for (int la = 1, ra = 1; l <= r; l += la, r -= ra) {
        if (!fl && num[l] > num[p]) {
            la = 0; //left add
            fl = true;
        } //if
        if (!fr && num[r] < num[p]) {
            ra = 0; //right add
            fr = true;
        } //if
        comparisons += 2;
        if (fl && fr) {
            swap(num[l], num[r]);
            fl = false;
            fr = false;
            la = 1;
            ra = 1;
        } //if
    } //for
    swap(num[p], num[r]);
    quickSortFP(num, start, r - 1);
    quickSortFP(num, r + 1, end);
} //quickSortRP

/**
 * A helper method for mergeSort.
 * Merges 2 arrays in ascending order.
 */
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
            comparisons++;
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

int * Sorting::buildMaxHeap(int num[], int size) {
    int * maxHeap = new int[size];
    for (int i = 0; i < size; i++) {
        maxHeap[i] = num[i];
        reheapUp(maxHeap, i);
    } //for
    return maxHeap;
} //buildMaxHeap

void Sorting::reheapUp(int num[], int b) {
    int p = (b - 1) / 2;
    if (b == 0) { //if there is one item
        return;
    } else if (num[p] < num[b]) {
        comparisons++;
        // perform a swap
        int temp = num[p];
        num[p] = num[b];
        num[b] = temp;
        reheapUp(num, p);
    } //if
} //reheapUp

void Sorting::reheapDown(int num[], int root, int b) {
    int l = root * 2 + 1;
    int r = root * 2 + 2;
    if (l > b) { //if  l is greater then it means r is also greater
        return;
    } else if (r > b) { //r is greater, but l is not, swap with l
        if (num[root] < num[l]) {
            swap(num[root], num[l]);
            reheapDown(num, l, b);
        } //if
        comparisons++;
    } else if (num[l] > num[r]) { //both are not greater, compare
        if (num[root] < num[l]) {
            swap(num[root], num[l]);
            reheapDown(num, l, b);
        } //if
        comparisons++;
        comparisons++;
    } else {
        if (num[root] < num[r]) {
            swap(num[root], num[r]);
            reheapDown(num, r, b);
        } //if
        comparisons++;
        comparisons++;
    } //if
} //reheapDown

//should make sure this works first
void Sorting::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
} //swap
