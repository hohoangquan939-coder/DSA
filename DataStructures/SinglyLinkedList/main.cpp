#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){

    LinkedList l1;

    l1.Insert_back(3);
    l1.Insert_back(8);
    int A[] = {1, 2, 3, 4, 5, 6};
    for(int i = 0; i < 6; i++){
        if(i%2) l1.Insert_back(A[i]);
        else l1.Insert_front(A[i]);
    }

    l1.Show();
    l1.Delete_front();
    l1.Show();
    l1.Delete_back();
    cout << l1;
    cout << l1.Size() << endl;
    cout << l1.Search(12) << endl;
    cout << l1.Empty() << endl;
    l1.Reverse();
    cout << l1 << endl;
    l1.Delete_value(2);
    cout << l1 << endl;
    return 0;
}