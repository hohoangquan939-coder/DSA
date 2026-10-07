#include "Node.h"

class BST{
    public: 
        Node* root;
        int size;

        BST();
        ~BST();

        int Size();
        bool Empty();

    private:
        void Preorder(Node*);
        void Inorder(Node*);
        void Postorder(Node*);

        Node* FindNodeInsert(int, Node*);
        void DeleteTree(Node*); // is used in Destructor
        Node* FindFather(Node*, int x);
        Node* Search_node(Node*, int);
        Node* FindInorderSuccessor(Node*);
        
    public:
        void Preorder_Show();
        void Inorder_Show();
        void Postorder_Show();
        
        bool Search(int x);
        
        void Insert(int);
        void Delete(int);
};