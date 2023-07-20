#include <iostream>
#include <algorithm>
#include <string.h>

#include "utilities.hpp"

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
    // -reversed
    // -nearly  
    
    // Hàm commandLineParser sẽ đọc các argument và đưa ra số nguyên biểu thị chế độ chạy
    int mode = commandLineParser(argc, argv);
    
    switch (mode){
        case 1:
            cout << "ALGORITHM MODE\n";
            AlgorithmMode(argc,argv);
            break;
        case 2:
            // Các chế độ sau cứ thêm vào, 2, 3, 4...
            cout << "IDK\n";
            break;
        default:
            cout << "You have not provided any additional argument\n";
    }
    
    return 0;
}

