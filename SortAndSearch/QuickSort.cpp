#include <iostream>
using namespace std;

// This is just a hoare-style partition. it's not the exact hoare partition bruh 
void quicksort(int A[], int left, int right){
    if (left >= right) return;

    int pivot = left, i = left+1, j = right; 
    while(i <= j){
        while(i <= right && A[i] <= A[pivot]) i++;
        while(j > left && A[j] >= A[pivot]) j--;

        if(i <= j){
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[pivot];
    A[pivot] = A[j];
    A[j] = tmp;

    quicksort(A, left, j-1);
    quicksort(A, j+1, right);
}

int main(){

    int A[] = {2, 1};
    quicksort(A, 0, 1);
    for(int i = 0; i < 2; i++){
        cout << A[i] << " ";
    }

    return 0;
}
