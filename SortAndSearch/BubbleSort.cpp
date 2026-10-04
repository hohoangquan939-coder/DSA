#include <iostream>
using namespace std;

void bubble_sort(int n, int A[]){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n-i; j++){
            if(A[j] > A[j+1]){
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }

    bubble_sort(n, A);

    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    delete[] A;
    return 0;
}