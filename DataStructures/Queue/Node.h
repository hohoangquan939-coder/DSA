
class Node{
    // If u want to access private members, u need to use getters and setters 
    private:
        int data;
        Node* next;
    
    public:
        Node(int = 0, Node* = nullptr);

        void Set_data(int);
        int Get_data();
        void Set_next_node(Node*);
        Node* Get_next_node();
};

