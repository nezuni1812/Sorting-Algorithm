#include <iostream>
#include <algorithm>

#include "DataGenerator.cpp"
#include "SortAlgorithm.h"

using namespace std;

void printArr(int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main(int argc, char* argv[]){
    int a[800];
    int n = sizeof(a)/sizeof(a[0]);
    
    GenerateData(a, n, 0);
    
    printArr(a, n);
    
    cout << "-----------------\n";
        
    unsigned long long comp = 0;
    FlashComp(a, n, comp);
    
    printArr(a, n);
    cout << "Comparisons: " << comp << "\n";
    
    return 0;
}