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
    
    int mode = commandLineParser(argc, argv);
    
    switch (mode){
        case 1:
            cout << "Algorithm Mode\n";
            AlgorithmMode(argc,argv);
            break;
        case 2:
            cout << "IDK\n";
            break;
        default:
            cout << "You have not provide any additional argument\n";
    }
    
    return 0;
}

