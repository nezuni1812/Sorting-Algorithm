#include <iostream>

using namespace std;

void Selection() {

}

void SelectionComp(int a[], int n, unsigned long long &compare){
    for (int i = 0; ++compare && i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; ++compare && j < n; ++j) 
            if (++compare && a[j] < a[minIndex]) 
                minIndex = j;
        swap(a[i], a[minIndex]);
    }
}

void Insertion() {

}

void InsertionComp(int a[], int n, unsigned long long &compare){
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

void Bubble() {

}

void BubbleComp() {

}

void Shaker() {

}

void ShakerComp() {

}

void Shell() {

}

void ShellComp() {

}

void Heap() {

}

void HeapComp() {

}

void Merge() {

}

void MergeComp() {

}

void Quick() {

}

void QuickComp() {

}

void CountingComp() {

}

void RadixComp() {

}

void FlashComp() {

}