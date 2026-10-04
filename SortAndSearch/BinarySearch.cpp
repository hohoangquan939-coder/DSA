#include <iostream>
using namespace std;

// The array needs to be sorted first 
// Best: O(1) - Worst: O(logn) - Average: O(logn)
bool binary_search(int [], int, int, int); // declare the func


int main(){

    int A[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    cout << binary_search(A, 0, 8, 100) << " " << binary_search(A, 0, 8, 3);

    return 0;
}

// define the func
bool binary_search(int A[], int i, int j, int x){
    if(i > j) return false;

    int k = (i + j) / 2;

    if(A[k] == x) return true;
    else if (A[k] > x) return binary_search(A, i, k-1, x); 
    else return binary_search(A, k+1, j, x);
}