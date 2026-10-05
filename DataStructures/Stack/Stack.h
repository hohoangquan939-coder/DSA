#include "Node.h"

class Stack{
    private:
        int size;
        Node* top;

    public:
        Stack();
        ~Stack();
        
        bool Empty();
        int Size();
        int Top();
        void Show();

        int Pop();
        void Push(int x);
};