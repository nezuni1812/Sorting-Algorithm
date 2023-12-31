#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <vector>

#include "DataGenerator.cpp"
#include "SortAlgorithm.h"

// Ngăn cách trước khi hiện kết quả
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

// Xác định xem chuỗi C string toàn kí tự số hay không
bool containAllNum(char *a){
    int index = 0;
    while (a[index]){
        if (!('0' <= a[index] && a[index] <= '9'))
            return false;
        index++;
    }
            
    return true;
}

// Chuyển tất cả thành kí tự viết thường
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
    // Nếu không có argument, argc == 1 -> return 0
    if (argc == 1)
        return 0;
        
    // Nếu ở mode Algorithm -> return 1
    if (strcmp(argv[1], "-a") == 0)
        return 1;
        
    // Nếu ở mode Comparison -> return 2
    if (strcmp(argv[1], "-c") == 0)
        return 2;
        
    return 0;
}

// Cho Command 2 và 5
void writeTo(string fileName, int *arr, int n){
    ofstream out(fileName.c_str());
    
    out << n << "\n";
    
    for (int i = 0; i < n; i++)
        out << arr[i] << " ";
        
    out.close();
}

// Chạy sort theo tên
void runSort(int a[], int n, string name = "radix-sort"){
    name = lower(name);
    
    // cout << "Running " << name << "\n";
    
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
        cout << "You have mistyped the sort alg's name.\nWe will run Quick sort by default.\n";
        Quick(a, 0, n - 1);
    }
}

// Chạy sort có đếm comparison theo tên 
void runSortComp(int a[], int n, string name, unsigned long long &comp){
    name = lower(name);
    
    // cout << "Running " << name << "\n";
    
    if (name == "selection-sort")
        SelectionComp(a, n, comp);
    else if (name == "insertion-sort")
        InsertionComp(a, n, comp);
    else if (name == "bubble-sort")
        BubbleComp(a, n, comp);
    else if (name == "shaker-sort")
        ShakerComp(a, n, comp);
    else if (name == "shell-sort")
        ShellComp(a, n, comp);
    else if (name == "heap-sort")
        HeapComp(a, n, comp);
    else if (name == "merge-sort")
        MergeComp(a, 0, n - 1, comp);
    else if (name == "quick-sort")
        QuickComp(a, 0, n - 1, comp);
    else if (name == "counting-sort")
        CountingComp(a, n, comp);
    else if (name == "radix-sort")
        RadixLSDComp(a, n, comp);
    else if (name == "flash-sort")
        FlashComp(a, n, comp);
    else{
        cout << "バーカ(￣ε(#￣).\n";
        QuickComp(a, 0, n - 1, comp);
    }
}

void AlgorithmMode(int argc, char* argv[]){
    if (argc < 5){
        cout << "Not enough arguments for Algorithm Mode\n";
        return;
    }
    
    /* 
    Pseudo code:
    
    if (there is a file name)
        do Command 1:
            open file
            turn file's content to a vector, then make a allocated array from that vector
            make two copies of dateset
            if (-both or -time)
                sort and output time
            if (-both or -comp)
                sort and output comparison count
    else
        if (argument count < 6)
            do Command 3:
                for order in all_dataset_orders:
                    make two copies of dateset
                    if (-both or -time)
                        sort and output time
                    if (-both or -comp)
                        sort and output comparison count
                
        else
            do Command 2:
                get dataset order
                make two copies of dateset
                if (-both or -time)
                    sort and output time
                if (-both or -comp)
                    sort and output comparison count
                
     */
    
    // Kiểm xem chuỗi ở index thứ 3 không chứa toàn kí tự số hay không, nếu là tên file, input.txt,..., -> chạy Command 1 else -> chạy Command 2 hoặc 3
    if (!containAllNum(argv[3])){
        // Command 1
        
        ifstream in(argv[3]);
        
        string temp;
        cout << "Algorithm: " << argv[2] << "\n";
        cout << "Input file: " << argv[3] << "\n";
        
        vector<int> numbers;
        
        int so;
        int n;
        in >> n;
        while (in >> so)
            numbers.push_back(so);
            
        // Đưa các số từ mảng vector vào mảng cấp phát động
        n = numbers.size();
        int *arr = new int [n];
        for (int i = 0; i < n; i++)
            arr[i] = numbers[i];
        int *arrComp = copyArr(arr, n);
            
        cout << "Input size: " << n << "\n";
    
        cout << DIVIDER;
        
        // Bấm giờ
        if (argc > 4 && (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)){
            clock_t start = clock();
            runSort(arr, n, argv[2]);
            clock_t now = clock();
            
            cout << "Running time (if required): " << static_cast<double>(now - start) / CLOCKS_PER_SEC << "\n";
        }
        
        // Đếm comparison
        if (argc > 4 && (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)){
            unsigned long long comp = 0;
            runSortComp(arrComp, n, argv[2], comp);
            
            cout << "Comparisons (if required): " << comp << "\n";
        }
        
        
        // Viết ra file
        if (argc > 4 && (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0))
            writeTo("output.txt", arr, n);
        else
            writeTo("output.txt", arrComp, n);
        
        delete []arr;
        delete []arrComp;
        
        in.close();
        
    }
    else {
        // Đầu vào cho cả Command 2 và 3
        
        int aSize = atoi(argv[3]);
        
        // Nếu số lượng argument ít hơn 6 -> chạy Command 3 else -> chạy Command 2
        if (argc < 6){
            // Command 3
            
            cout << "Algorithm: " << argv[2] << "\n";
            cout << "Input size: " << aSize << "\n";
            
            
            // Vòng lặp chạy hết các kiểu thứ tự của dữ liệu
            for (int i = 0; i < 4; i++) {
                int *arrStock = new int [aSize];
                GenerateData(arrStock, aSize, i);
                int *arr = copyArr(arrStock, aSize);
                int *arrComp = copyArr(arrStock, aSize);
                
                cout << "\nInput order: ";          
                //In generated input vào file .txt
                switch(i) {
                    case 0:
                        cout << "Randomize\n";
                        writeTo("input_1.txt", arr, aSize);
                        break;
                    case 1:
                        cout << "Sorted\n";
                        writeTo("input_3.txt", arr, aSize);
                        break;
                    case 2:
                        cout << "Reversed Sorted\n";
                        writeTo("input_4.txt", arr, aSize);
                        break;
                    case 3:
                        cout << "Nearly Sorted\n";
                        writeTo("input_2.txt", arr, aSize);
                        break;
                }
                cout << DIVIDER;
                
                
                // Bấm giờ
                if (argc > 4 && (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)){
                    const clock_t start = clock();
                    runSort(arr, aSize, argv[2]);
                    clock_t now = clock();
                    cout << "Running time (if required): " << static_cast<double>(now - start) / CLOCKS_PER_SEC << endl;
                    
                }
                
                // Đếm comparison
                if (argc > 4 && (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)){
                    unsigned long long comp = 0;
                    runSortComp(arrComp, aSize, argv[2], comp);
                    cout << "Comparisons (if required): " << comp << endl;
                    
                }
                
                
                delete []arr;
                delete []arrComp;
                delete []arrStock;
            }
            

        }
        
        else {
            // Command 2
            
            int order = 0;
            if (strcmp(argv[4], "-rand") == 0)
                order = 0;
            if (strcmp(argv[4], "-sorted") == 0)
                order = 1;
            if (strcmp(argv[4], "-rev") == 0)
                order = 2;
            if (strcmp(argv[4], "-nsorted") == 0)
                order = 3;
            
            cout << DIVIDER;
            
            // Tạo dữ liệu
            int *arr = new int [aSize];
            GenerateData(arr, aSize, order);
            int *arrComp = copyArr(arr, aSize);
            
            // Viết ra file
            writeTo("input.txt", arr, aSize);
            
            // Bấm giờ
            if (argc > 4 && (strcmp(argv[5], "-both") == 0 || strcmp(argv[5], "-time") == 0)){
                const clock_t start = clock();
                runSort(arr, aSize, argv[2]);
                clock_t now = clock();
                
                cout << "Running time (if required): " << static_cast<double>(now - start) / CLOCKS_PER_SEC << endl;
            }
            
            // Đếm comparisons
            if (argc > 4 && (strcmp(argv[5], "-both") == 0 || strcmp(argv[5], "-comp") == 0)){
                unsigned long long comp = 0;
                runSortComp(arrComp, aSize, argv[2], comp);
                
                cout << "Comparisons (if required): " << comp << "\n";
            }
            
            // Viết ra file
            if (argc > 4 && (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0))
                writeTo("output.txt", arr, aSize);
            else
                writeTo("output.txt", arrComp, aSize);
            
            delete []arr;
            delete []arrComp;
        }
    }

}

void ComparisonMode(int argc, char* argv[]) {
    /* 
    Pseudo code:
    
    if (there argv[4] is not a number => it's a file's name)
        do Command 4:
            open file
            turn file's content to a vector, then make a allocated array from that vector
            make three more copies of dateset
                count run time of sort 1
                count run time of sort 2

                count comparisons of sort 1
                count comparisons of sort 2
    else
        do Command 5:
            for order in all_dataset_orders:
                make three more copies of dateset
                    count run time of sort 1
                    count run time of sort 2

                    count comparisons of sort 1
                    count comparisons of sort 2
     */
    if (argc < 5){
        cout << "Not enough arguments for Comparison Mode\n";
        return;
    }

    cout << "Algorithm: " << argv[2] << " | " << argv[3] << "\n";

    //Command 4 Sort theo file cho sẵn
    if (!containAllNum(argv[4])){
        ifstream ifs(argv[4]);
        
        cout << "Input file: " << argv[4] << "\n";
        
        vector<int> list;
        
        int data;
        int n;
        ifs >> n;
        while (ifs >> data)
            list.push_back(data);
        
        ifs.close();
        // Đưa các số từ mảng vector vào mảng cấp phát động
        n = list.size();
        int *arr = new int [n];
        for (int i = 0; i < n; i++)
            arr[i] = list[i];
        
        // Mảng phụ dùng cho Sort 2 và đếm comparisons của 2 sort
        int *arr2 = copyArr(arr, n);
        int *arrComp = copyArr(arr, n);
        int *arr2Comp = copyArr(arr, n);
            
        cout << "Input size: " << n << "\n";
        cout << DIVIDER;

        // Đếm giờ Sort 1
        const clock_t start = clock();
        runSort(arr, n, argv[2]);
        clock_t now = clock();
        
        cout << "Running time: " << static_cast<double>(now - start) / CLOCKS_PER_SEC << " | ";
        
        //Đếm giờ Sort 2
        const clock_t start2 = clock();
        runSort(arr2, n, argv[3]);
        clock_t now2 = clock();

        cout << static_cast<double>(now2 - start2) / CLOCKS_PER_SEC << "\n";

        //Đếm comparisons 2 sort
        unsigned long long comp1 = 0, comp2 = 0;
        runSortComp(arrComp, n, argv[2], comp1);
        runSortComp(arr2Comp, n, argv[3], comp2);
        cout << "Comparisons: " << comp1 << " | " << comp2;

        delete []arr;
        delete []arr2;
        delete []arrComp;
        delete []arr2Comp;
    }
    else { //Command 5 Sort theo yêu cầu
        
        int n = atoi(argv[4]);
        int *arr = new int [n];

        int order = 0;
        if (strcmp(argv[5], "-rand") == 0)
            order = 0;
        if (strcmp(argv[5], "-sorted") == 0)
            order = 1;
        if (strcmp(argv[5], "-rev") == 0)
            order = 2;
        if (strcmp(argv[5], "-nsorted") == 0)
            order = 3;

        cout << "Input size: " << n << "\n";
        cout << "Input order: ";
        switch(order) {
            case 0:
                cout << "Randomize\n";
                break;
            case 1:
                cout << "Sorted\n";
                break;
            case 2:
                cout << "Reversed Sorted\n";
                break;
            case 3:
                cout << "Nearly Sorted\n";
                break;
        }
        
        //Tạo data theo yêu cầu về kiểu data
        GenerateData(arr, n, order);
        // Viết ra file
        writeTo("input.txt", arr, n);

        cout << DIVIDER;
        // Mảng phụ dùng cho Sort 2 và đếm comparisons của 2 sort
        int *arr2 = copyArr(arr, n);
        int *arrComp = copyArr(arr, n);
        int *arr2Comp = copyArr(arr, n);
        
        // Đếm giờ Sort 1
        const clock_t start = clock();
        runSort(arr, n, argv[2]);
        clock_t now = clock();
        
        cout << "Running time: " << static_cast<double>(now - start) / CLOCKS_PER_SEC << " | ";
        
        //Đếm giờ Sort 2
        const clock_t start2 = clock();
        runSort(arr2, n, argv[3]);
        clock_t now2 = clock();

        cout << static_cast<double>(now2 - start2) / CLOCKS_PER_SEC << "\n";

        //Đếm comparisons 2 sort
        unsigned long long comp1 = 0, comp2 = 0;
        runSortComp(arrComp, n, argv[2], comp1);
        runSortComp(arr2Comp, n, argv[3], comp2);
        cout << "Comparisons: " << comp1 << " | " << comp2;

        delete []arr;
        delete []arr2;
        delete []arrComp;
        delete []arr2Comp;
    }
}