#include "Node.h"

class HashTable{
    private:
        Node** table;
        int number;
        int capacity;
    
    public:
        HashTable(int = 1);
        ~HashTable();

        int HashFunc(int);
        void Show();
        void Insert(int);
        bool Search(int); 
        void Remove(int);
};