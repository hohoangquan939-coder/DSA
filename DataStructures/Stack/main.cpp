#include "Stack.h"
#include <iostream>
using namespace std;

int main(){

    int A[] = {1, 2, 33, 11, 0, 33, 9999, 3, 2, 565};
    Stack s;
    for(int i = 0; i < 10; i++){
        s.Push(A[i]);
    }
    s.Show();  
    s.Pop();
    s.Show();

}   