class Node{
    private:
        int data;
        Node* next;
    
    public:
        Node(int = 0, Node* = nullptr);
        ~Node();
        int get_data();
        void set_data(int);
        void set_next_node(Node*);
        Node* get_next_node();
};