// I will make Node's attributes public for easier access.

class Node{
    
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int = 0, Node* = nullptr, Node* = nullptr);
        ~Node();

};