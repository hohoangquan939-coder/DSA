#include <iostream> 
using namespace std;

void insertion_sort(int n, int A[]){
    for(int i = 1; i < n; i++){
        int tmp = A[i];
        int j = i;
        while( j>=1 && tmp < A[j-1] ){
            A[j] = A[j-1];
            j--;
        }
        A[j] = tmp;
    }
}

int main(){

    int n;
    cin >> n;
    int* A = new int[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    insertion_sort(n, A);

    for(int i = 0; i < n; ++i){
        cout << A[i] << " ";
    }

    cout << endl;
    delete[] A;

    return 0;
}