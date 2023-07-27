#include <iostream>
#include <algorithm>
#include <string.h>

#include "utilities.h"

using namespace std;

int main(int argc, char* argv[]){
    // Tên của các thuật sắp xếp:
    // selection-sort
    // insertion-sort
    // bubble-sort
    // shaker-sort
    // shell-sort
    // heap-sort
    // merge-sort
    // quick-sort
    // counting-sort
    // radix-sort
    // flash-sort
    
    // Tên kiểu sắp xếp:
    // -rand
    // -sorted
    // -rev
    // -nsorted  
    
    // Hàm commandLineParser sẽ đọc các argument và đưa ra số nguyên biểu thị chế độ chạy
    int mode = commandLineParser(argc, argv);
    
    switch (mode){
        case 1:
            cout << "ALGORITHM MODE\n";
            AlgorithmMode(argc,argv);
            break;
        case 2:
            cout << "COMPARE MODE\n";
            ComparisonMode(argc, argv);
            break;
        default:
            cout << "You have not provided any additional argument\n";
    }
    
    return 0;
}

