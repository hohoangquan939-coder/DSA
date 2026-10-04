#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int A[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && A[largest] < A[left]) largest = left;
    if(right < n && A[largest] < A[right]) largest = right;

    if(largest != i){
        swap(A[largest], A[i]);
        heapify(A, n, largest);
    }
}

void heap_sort(int A[], int n){
    // build max-heap
    for(int i = (n-1)/2; i >= 0; i--){
        heapify(A, n, i);
    }

    for(int i = n-1; i > 0; i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}



int main(){
    
    int A[] = {2, 3, 1, 4, 2, 5, 3, 1, 6, 2};
    heap_sort(A, 10);

    for(int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }

    return 0;
}