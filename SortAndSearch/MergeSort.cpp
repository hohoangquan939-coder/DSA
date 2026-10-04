#include <iostream>
using namespace std;

void merge(int n, int A[], int m, int B[], int C[]){
    int i = 0, j = 0;
    int k = 0;
    while(i < n && j < m){
        if( A[i] <= B[j] ) C[k++] = A[i++];
        else C[k++] = B[j++];
    }
    while(i < n) C[k++] = A[i++];
    while(j < m) C[k++] = B[j++];
}

void merge_sort(int n, int A[]){
    if(n <= 1) return;
    int k = n/2;
    int* B = new int[k];
    int* C = new int[n-k];

    for(int i = 0; i < k; i++){
        B[i] = A[i];
    }
    for(int i = k; i < n; i++){
        C[i-k] = A[i];
    }
    
    merge_sort(k, B);
    merge_sort(n-k, C);
    merge(k, B, n-k, C, A);
    delete[] B;
    delete[] C;
}

int main(){
    
    int n;
    cin >> n;
    int* A = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }

    merge_sort(n, A);
    
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    delete[] A;

    return 0;
}