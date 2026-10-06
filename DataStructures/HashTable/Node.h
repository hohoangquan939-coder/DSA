class Node{
    private:
        int data;
        Node* next;
    
    public:
        Node(int = 0, Node* = nullptr);

        int Get_data();
        void Set_data(int);
        Node* Get_next_node();
        void Set_next_node(Node*);
};