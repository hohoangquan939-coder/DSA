#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList{
    private: 
        Node* head;
    
    public:

        LinkedList(Node* = nullptr);
        ~LinkedList();

        void Show();
        int Size();
        bool Search(int);
        bool Empty();

        void Insert_front(int);
        void Insert_back(int);
        void Delete_front();
        void Delete_back();   
        void Delete_value(int);   
        
        void Reverse();

        friend ostream& operator<<(ostream&, const LinkedList&);
};

