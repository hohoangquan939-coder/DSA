#include <iostream>
using namespace std;

// Best: O(1) - Worst: O(n) - Average: O(n)

bool linear_search(int n, int A[], int x){
    for(int i = 0; i < n; i++){
        if(A[i] == x) return true;
    }
    return false;
}

int main(){

    int A[] = {1, 2, 3, 32, 0, -4, 2};
    cout << linear_search(7, A, 4) << " " << linear_search(7, A, -4) << endl;

    return 0;
}