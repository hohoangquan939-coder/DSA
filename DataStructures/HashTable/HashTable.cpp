#include <iostream>
#include "HashTable.h"
using namespace std;

HashTable::HashTable(int x) : capacity(x){
    this->number = 0;
    this->table = new Node*[this->capacity];

    for(int i = 0; i < this->capacity; i++){
        this->table[i] = nullptr; 
        // or u can use: *(this->table + i) = nullptr
    }
}

HashTable::~HashTable(){
    for(int i = 0; i < this->capacity; ++i){
        Node* p = *(this->table + i);
        while(p != nullptr){
            Node* tmp = p;
            p = p->Get_next_node();
            delete tmp;
        }
    }
    delete[] this->table;
}

int HashTable::HashFunc(int x){
    return abs(x % this->capacity);
}

void HashTable::Show(){
    for(int i = 0; i < this->capacity; i++){
        cout << "Key " << i << ": ";
        Node* p = *(this->table + i);
        while(p != nullptr){
            cout << p->Get_data() << " ";
            p = p->Get_next_node();
        }
        cout << endl;
    }
}

bool HashTable::Search(int x){
    int index = this->HashFunc(x);
    if(index < 0 || index >= this->capacity){ 
        cout << "Not valid" << endl;
        return false;
    }
    Node *p = *(this->table + index);

    while(p != nullptr){
        if(p->Get_data() == x) return true;
        p = p->Get_next_node(); 
    }
    return false;
}


void HashTable::Insert(int x){
    int index = this->HashFunc(x);
    if(index < 0 || index >= this->capacity){ 
        cout << "Not valid" << endl;
        return;
    }
    
    Node* a = new Node(x);
    this->number++;
    Node* p = *(this->table + index);

    if(p == nullptr){
        *(this->table + index ) = a;
        return;
    }
    while(p->Get_next_node() != nullptr){
        p = p->Get_next_node();
    }
    p->Set_next_node(a); 
}

void HashTable::Remove(int x){
    int index = this->HashFunc(x);
    if(index < 0 || index >= this->capacity){ 
        cout << "Not valid" << endl;
        return;
    }

    Node* p = *(this->table + index);
    if(p == nullptr){
        cout << "The value doesn't exist" << endl;
        return;
    }

    if(p->Get_data() == x){
        (*(this->table + index))= p->Get_next_node();
        delete p;
        this->number--;
        return;
    }

    while(p->Get_next_node() != nullptr && p->Get_next_node()->Get_data() != x){
        p = p->Get_next_node();
    }

    if(p->Get_next_node() == nullptr){
        cout << "The value doesn't exist" << endl;
        return;
    }

    Node* cur = p->Get_next_node();
    p->Set_next_node(cur->Get_next_node());
    delete cur;
    this->number--;
}