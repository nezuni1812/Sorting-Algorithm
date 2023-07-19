#include <iostream>

using namespace std;

void SelectionSort() {

}

void SelectionSortComp(int a[], int n, unsigned long long &compare){
    for (int i = 0; ++compare && i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; ++compare && j < n; ++j) 
            if (++compare && a[j] < a[minIndex]) 
                minIndex = j;
        swap(a[i], a[minIndex]);
    }
}

void InsertionSort() {

}

void InsertionSortComp(int a[], int n, unsigned long long &compare){
    for (int i = 1; ++compare && i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (++compare && j >= 0 && ++compare && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void BubbleSort() {

}

void BubbleSortComp() {

}

void ShakerSort() {

}

void ShakerSortComp() {

}

void ShellSort() {

}

void ShellSortComp() {

}

void HeapSort() {

}

void HeapSortComp() {

}

void MergeSort() {

}

void MergeSortComp() {

}

void QuickSort() {

}

void QuickSortComp() {

}

void CountingSortComp() {

}

void RadixSortComp() {

}

void FlashSortComp() {

}