#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>

#include "DataGenerator.cpp"
#include "SortAlgorithm.h"

using namespace std;

void printArr(int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int *copyArr(int *a, int n){
    int *temp = new int [n];
    
    for (int i = 0; i < n; i++)
        temp[i] = a[i];
        
    return temp;
}

int commandLineParser(int argc, char* argv[]){
    if (argc == 1)
        return 0;
        
    if (strcmp(argv[1], "-a") == 0)
        return 1;
        
    return 2;
}

void test(){
    int a[800];
    int n = sizeof(a)/sizeof(a[0]);
    
    GenerateData(a, n, 0);
    
    printArr(a, n);
    
    cout << "-----------------\n";
        
    unsigned long long comp = 0;
    FlashComp(a, n, comp);
    
    printArr(a, n);
    cout << "Comparisons: " << comp << "\n";
    
}

bool isAlpha(char *a){
    int index = 0;
    while (a[index++])
        if (!a[index])
            return false;
            
    return true;
}

void AlgorithmMode(int argc, char* argv[]){
//     Command 1: Run a sorting algorithm on the given input data.
// - Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
// - Ex: a.exe -a radix-sort input.txt -both

// Command 2: Run a sorting algorithm on the data generated automatically with specified
// size and order.
// – Prototype: [Execution file] -a [Algorithm] [Input size] [Input order]
// [Output parameter(s)]
// – Ex: a.exe -a selection-sort 50 -rand -time

// Command 3: Run a sorting algorithm on ALL data arrangements of a specified size.
// – Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
// – Ex: a.exe -a binary-insertion-sort 70000 -comp

    if (argc < 5){
        cout << "Not enough arguments for Algorithm Mode\n";
        return;
    }
    
    if (isAlpha(argv[3])){
        ifstream in(argv[3]);
        
        string temp;
        cout << "The sorting algo to use is: " << argv[2] << "\n";
        cout << "The file to read from is: " << argv[3];
        
        in.close();
        
    }
    else {
        cout << "Auto generate\n";
        
        int aSize = atoi(argv[3]);
        
        if (strcmp(argv[4], "-comp") == 0){
            int *arr = new int [aSize];
            
            for (int i = 0; i < 4; i++){
                GenerateData(arr, aSize, i);
                
                const clock_t start = clock();
                RadixLSD(arr, aSize);
                clock_t now = clock();
                clock_t delta = now - start;
                double seconds_elapsed = static_cast<double>(delta) / CLOCKS_PER_SEC;
                cout << "Thoi gian chay la: " << seconds_elapsed << endl;
                
                // printArr(arr, aSize);
                cout << "---------------\n";
                
            }
            
            delete []arr;
        }
    }

}