#include <iostream>
#include "AvlTree.h"
using namespace std;

int main(){

    AvlTree a;
    
    int A[] = {1, 3, 2, 5, 3, 6, 2, 1, 7, 4, 2, 1, 7, 5, 2, 1};
    
    for(int i = 0; i < 16; i++){
        a.Insert(A[i]);
    }

    a.Show();

    return 0;
}