#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    this->size = 0;
    this->front = nullptr;
    this->behind = nullptr;
}

Queue::~Queue(){
    Node* p = this->front;
    while(p != nullptr){
        Node* cur = p;
        p = p->Get_next_node();
        delete cur;
    }
    this->front = nullptr;
    this->behind = nullptr;
    this->size = 0;
}

int Queue::Size(){
    return this->size;
}

bool Queue::Empty(){
    return this->size == 0;
}

int Queue::Front(){
    if(this->size == 0){
        cout << "Queue is empty" << endl;
        return -1;
    }
    return this->front->Get_data();
}

int Queue::Rear(){
    if(this->size == 0){
        cout << "Queue is empty" << endl;
        return -1;
    }
    return this->behind->Get_data();
}

void Queue::Show(){
    Node* p = this->front;
    while(p != nullptr){
        cout << p->Get_data() << " ";
        p = p->Get_next_node();
    }
    cout << endl;
}

void Queue::Enqueue(int x){
    Node* q = new Node(x);
    if(this->size == 0){
        this->front = q;
        this->behind = q;
        this->size += 1;
        return;
    }

    this->behind->Set_next_node(q);
    this->behind = this->behind->Get_next_node();
    this->size++;
}

void Queue::Dequeue(){
    if(this->size == 0){
        cout << "Queue is empty" << endl;
        return;
    }
    this->size--;
    Node* p = this->front;
    this->front = this->front->Get_next_node();
    delete p;

    if(this->size == 0) this->behind = nullptr;
}