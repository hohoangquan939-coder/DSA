#include "Node.h"
#include <iostream>
using namespace std;

class Queue{
    private:
        int size;
        Node* front;
        Node* behind;
    
    public:
        Queue();
        ~Queue();

        int Size();
        void Show();
        int Front();
        int Rear();
        bool Empty();

        void Enqueue(int);
        void Dequeue();

        friend ostream& operator<<(ostream&, const Queue&);
};