#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <vector>

#include "DataGenerator.cpp"
#include "SortAlgorithm.h"

#define DIVIDER "-------------------------\n"

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

// Xác định xem chuỗi C string toàn kí tự chữ hay không
bool isAlpha(char *a){
    int index = 0;
    cout << a << "\n";
    while (a[index++])
        if (!a[index])
            return false;
            
    cout << "All alphabetical\n";
    return true;
}

bool containAllNum(char *a){
    int index = 0;
    while (a[index++])
        if (!('0' <= a[index] && a[index] <= '9'))
            return false;
            
    return true;
}

string lower(string a){
    string temp = "";
    
    for (int i = 0; i < a.size(); i++)
        if ('A' <= a[i] && a[i] <= 'Z')
            temp += a[i] + ' ';
        else
            temp += a[i];
            
    return temp;
}

int commandLineParser(int argc, char* argv[]){
    // Nếu không có argument -> argc == 1
    if (argc == 1)
        return 0;
        
    // Nếu ở mode Algorithm -> return 1
    if (strcmp(argv[1], "-a") == 0)
        return 1;
        
    // Mấy mode còn lại return ở số 2, 3, 4
        
    return 0;
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

void runSort(int a[], int n, string name = "radix-sort"){
    name = lower(name);
    
    cout << "Running " << name << "\n";
    
    if (name == "selection-sort")
        Selection(a, n);
    else if (name == "insertion-sort")
        Insertion(a, n);
    else if (name == "bubble-sort")
        Bubble(a, n);
    else if (name == "shaker-sort")
        Shaker(a, n);
    else if (name == "shell-sort")
        Shell(a, n);
    else if (name == "heap-sort")
        Heap(a, n);
    else if (name == "merge-sort")
        Merge(a, 0, n - 1);
    else if (name == "quick-sort")
        Quick(a, 0, n - 1);
    else if (name == "counting-sort")
        Counting(a, n);
    else if (name == "radix-sort")
        RadixLSD(a, n);
    else if (name == "flash-sort")
        Flash(a, n);
    else{
        cout << "You stoopid, you misstyped the sort alg's name.\nWe will run Quick sort by default.\n";
        Quick(a, 0, n - 1);
    }
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
    
    if (!containAllNum(argv[3])){
        ifstream in(argv[3]);
        
        string temp;
        cout << "Algorithm: " << argv[2] << "\n";
        cout << "Input file: " << argv[3];
        
        vector<int> numbers;
        
        int so;
        while (in >> so)
            numbers.push_back(so);
            
        // Đưa các số từ mảng vector vào mảng cấp phát động
        int n = numbers.size();
        int *arr = new int [n];
        for (int i = 0; i < n; i++)
            arr[i] = numbers[i];
            
        cout << "Input size: " << n << "\n";
        
        cout << DIVIDER;
        
        
        clock_t start = clock();
        
        runSort(arr, n, argv[2]);
        
        clock_t now = clock();
        
        cout << "Running time (if required): " << static_cast<double>(now - start) / CLOCKS_PER_SEC << "\n";
        
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
                
                runSort(arr, aSize, argv[2]);
                
                clock_t now = clock();
                double seconds_elapsed = static_cast<double>(now - start) / CLOCKS_PER_SEC;
                cout << "Thoi gian chay la: " << seconds_elapsed << endl;
                
                // printArr(arr, aSize);
                cout << "---------------\n";
                
            }
            
            delete []arr;
        }
    }

}