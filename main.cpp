#include <iostream>
#include <algorithm>
#include <string.h>

#include "utilities.hpp"

using namespace std;

int main(int argc, char* argv[]){
    // Algorithm mode
    // a.exe -a radix-sort input.txt -both
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

