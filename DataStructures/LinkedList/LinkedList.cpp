#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(Node* p): head(p){
}

LinkedList::~LinkedList(){
    Node* p = this->head;
    while(p != nullptr){
        Node* cur = p;
        p = p->get_next_node();
        delete cur;
    }
}

void LinkedList::Show(){
    Node* p = this->head;
    while(p != nullptr){
        cout << p->get_data() << " ";
        p = p->get_next_node();
    }
    cout << endl;
}

bool LinkedList::Empty(){
    return this->head == nullptr;
}

int LinkedList::Size(){
    int res = 0;
    Node* p = this->head;
    while(p != nullptr){
        res++;
        p = p->get_next_node();
    }
    return res;
}

bool LinkedList::Search(int x){

    Node* p = this->head;
    while(p != nullptr){
        if(p->get_data() == x) return true;
        p = p->get_next_node();
    }
    return false;
}

void LinkedList::Insert_front(int x){
    Node* p1 = new Node(x);
    p1->set_next_node(this->head);
    this->head = p1;
}

void LinkedList::Insert_back(int x){
    Node* p1 = new Node(x);
    if(this->head == nullptr){
        this->head = p1;
        return;
    }
    Node* p = head;
    while(p->get_next_node() != nullptr){
        p = p->get_next_node();
    }
    p->set_next_node(p1);
}

void LinkedList::Delete_front(){
    if(this->head == nullptr){
        cout << "Linked_List is empty" << endl;
        return;
    }
    Node* p = this->head;
    this->head = this->head->get_next_node();
    delete p;
    p = nullptr;
}

void LinkedList::Delete_back(){
    if(this->head == nullptr){
        cout << "Linked_List is empty" << endl;
        return;
    }

    // 1 node
    if(this->head->get_next_node() == nullptr){
        delete this->head;
        this->head = nullptr;
        return;
    }

    Node* p = this->head;
    while(p->get_next_node()->get_next_node() != nullptr){
        p = p->get_next_node();
    }
    Node *d = p->get_next_node();
    delete d;
    p->set_next_node(nullptr);
}

ostream& operator<<(ostream& o, const LinkedList& l ){
    Node* p = l.head;
    while(p != nullptr){
        o << p->get_data() << " ";
        p = p->get_next_node();
    }
    o << endl;
    return o;
}

void LinkedList::Delete_value(int x){
    if(this->head == nullptr) return;
    if(this->head->get_data() == x){
        this->Delete_front();
        return;
    }

    Node*p = this->head;
    while(p->get_next_node() && p->get_next_node()->get_data() != x){
        p = p->get_next_node();
    }
    if(p->get_next_node() == nullptr) cout << "Linked List khong co gia tri x" << endl;
    else{
        Node* p1 = p->get_next_node();
        p->set_next_node(p1->get_next_node()); 
        delete p1;
    }
}

void LinkedList::Reverse(){
    if(this->head == nullptr || this->head->get_next_node() == nullptr) return;

    Node* prev = this->head;
    Node* cur = prev->get_next_node();
    Node* fur = cur->get_next_node();

    prev->set_next_node(nullptr);

    while(cur != nullptr){
        cur->set_next_node(prev);
        prev = cur;
        cur = fur;
        if(fur != nullptr)  fur = fur->get_next_node();
    }
    this->head = prev;
} 