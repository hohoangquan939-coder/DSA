// this is the first time i've implemented AVL
// So if i make any mistakes, please forgive me 
// To be honeset, this data structures is really difficult for me 
// So i had to use AI to help me implement the AVL Tree

#include "Node.h"

class AvlTree{
    private:
        void Delete(Node*);
        bool Search(int, Node*);
        int GetHeight(Node*);
        int GetBalance(Node*);

        Node* Insert(Node*, int); // Overload
        void Remove(Node*, int); // Overload

        Node* RotateLeft(Node*);
        Node* RotateRight(Node*);
        void Show(Node*, int = 0);
        
    public:
        Node* root;
        
        AvlTree();
        ~AvlTree();

        void Show();
        bool Empty();
        bool Find(int);

        void Insert(int);
        void Remove(int);

};