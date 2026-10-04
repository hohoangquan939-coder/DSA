#include <iostream>
using namespace std;

void selection_sort(int n, int A[]){
    for(int i = 0; i < n-1; i++){
        int min_post = i;
        for(int j = i+1; j < n; j++){
            if(A[j] < A[min_post]) min_post = j;
        }
        if(min_post != i){
            int tmp = A[min_post];
            A[min_post] = A[i];
            A[i] = tmp;
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

    selection_sort(n, A);

    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    delete[] A;
    return 0;
}