#include <iostream>
#include <fstream>

#include "utilities.hpp"

using namespace std;

int main(){
    ofstream out("Sorting-Datapoints2.csv");
    
    // "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", 
    vector<string> sortingNames = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort",  "quick-sort", "counting-sort", "radix-sort", "flash-sort"};
    vector<int> sortingSizes = {10000, 30000, 50000, 100000, 300000, 500000};

    
    for (int i = 0; i < 4; i++){
        int *arr10 = new int [10000];
        GenerateData(arr10, 10000, i);
        int *arr30 = new int [30000];
        GenerateData(arr30, 30000, i);
        int *arr50 = new int [50000];
        GenerateData(arr50, 50000, i);
        int *arr100 = new int [100000];
        GenerateData(arr100, 100000, i);
        int *arr300 = new int [300000];
        GenerateData(arr300, 300000, i);
        int *arr500 = new int [500000];
        GenerateData(arr500, 500000, i);
        
        
        vector<int *> arrPointList = {arr10, arr30, arr50, arr100, arr300, arr500};
        
        // Output order name
        switch(i) {
            case 0:
                cout << "\n- Randomize:\n";
                out << "\nRandomize\n";
                break;
            case 1:
                cout << "\n- Sorted:\n";
                out << "\nSorted\n";
                break;
            case 2:
                cout << "\n- Reversed Sorted:\n";
                out << "\nReversed Sorted\n";
                break;
            case 3:
                cout << "\n- Nearly Sorted:\n";
                out << "\nNearly Sorted\n";
                break;
        }
        
        out << "Data size, ";
        for (int i = 0; i < sortingSizes.size(); i++)
            for (int j = 0; j < 2; j++)
                out << sortingSizes[i] << ", "; 
        out << "\n";
        
        out << "Resulting statics, ";
        for (int i = 0; i < sortingSizes.size(); i++)
            out << "Running time, Comparisons, "; 
        out << "\n";
        
        for (int j = 0; j < sortingNames.size(); j++){
            cout << sortingNames[j] << ": ";
            out << sortingNames[j] << ", ";
            
            
            for (int b = 0; b < arrPointList.size(); b++){
                
                int *forSorting = copyArr(arrPointList[b], sortingSizes[b]);
                int *forComp = copyArr(arrPointList[b], sortingSizes[b]);
                int n = sortingSizes[b];
                
                const clock_t start = clock();
                runSort(forSorting, n, sortingNames[j]);
                clock_t now = clock();
                out << static_cast<double>(now - start) / CLOCKS_PER_SEC << ", ";
                out.flush();
                
                unsigned long long comp = 0;
                runSortComp(forComp, n, sortingNames[j], comp);
                out << comp << ", ";
                out.flush();
                
                delete []forSorting;
                delete []forComp;
                
                cout << sortingSizes[b] << " finished, ";
            }
            
            out << "\n";
            cout << "\n";
        }
        
        delete []arr10; 
        delete []arr30; 
        delete []arr50; 
        delete []arr100;
        delete []arr300;
        delete []arr500;
    }
    
    
    out.close();
    
    return 0;
}