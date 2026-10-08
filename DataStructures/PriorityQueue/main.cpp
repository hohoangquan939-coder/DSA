#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {

    PriorityQueue pq;

    cout << "Empty: " << pq.Empty() << endl;
    cout << "Size: " << pq.Size() << endl;

    cout << "\nPush: 10, 5, 20, 15, 8" << endl;

    pq.Push(10);
    pq.Push(5);
    pq.Push(20);
    pq.Push(15);
    pq.Push(8);

    cout << "Queue: ";
    pq.Show();

    cout << "Top: " << pq.Top() << endl;
    cout << "Size: " << pq.Size() << endl;

    cout << "\nPop..." << endl;
    pq.Pop();

    cout << "Queue: ";
    pq.Show();

    cout << "Top: " << pq.Top() << endl;
    cout << "Size: " << pq.Size() << endl;

    cout << "\nPop all:" << endl;

    while (!pq.Empty()) {
        cout << "Top: " << pq.Top() << endl;
        pq.Pop();
    }

    cout << "\nEmpty: " << pq.Empty() << endl;
    cout << "Size: " << pq.Size() << endl;

    return 0;
}