class Node{
    private:
        int data;
        Node* next;
    
    public:
        Node(int = 0, Node* = nullptr);
        ~Node();

        void Set_data(int);
        int Get_data();
        void Set_next_node(Node*);
        Node* Get_next_node();
        
};
