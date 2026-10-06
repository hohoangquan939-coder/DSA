#include "Queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue q;

    // Test Empty() and Size()
    cout << "Empty: " << q.Empty() << endl;
    cout << "Size: " << q.Size() << endl;

    // Test Enqueue()
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "\nAfter Enqueue:" << endl;
    q.Show();

    // Test Size()
    cout << "Size: " << q.Size() << endl;

    // Test Front() and Rear()
    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    // Test Dequeue()
    q.Dequeue();

    cout << "\nAfter Dequeue:" << endl;
    q.Show();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.Size() << endl;

    // Dequeue remaining elements
    q.Dequeue();
    q.Dequeue();

    cout << "\nAfter removing all elements:" << endl;
    q.Show();

    cout << "Empty: " << q.Empty() << endl;
    cout << "Size: " << q.Size() << endl;

    // Test Front(), Rear() when empty
    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    // Test Dequeue() when empty
    q.Dequeue();

    return 0;
}