#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
    this->size = 0;
    this->top = nullptr;
}

Stack::~Stack(){
    Node* p = this->top;
    while(p != nullptr){
        Node* cur = p;
        p = p->Get_next_node();
        delete cur;
    }
    this->top = nullptr;
    this->size = 0;
}

bool Stack::Empty(){
    return this->size == 0;
}

int Stack::Size(){
    return this->size;
}

void Stack::Show(){
    Node* p = this->top;
    while(p != nullptr){
        cout << p->Get_data() << " ";
        p = p->Get_next_node();
    }
    cout << endl;
}

int Stack::Top(){
    if(this->top == nullptr){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return this->top->Get_data();
}

int Stack::Pop(){
    if(this->top == nullptr){
        cout << "Stack is empty" << endl;
        return -1;
    }
    int res = this->top->Get_data();
    Node* tmp = this->top;
    this->top = tmp->Get_next_node();
    this->size--;
    delete tmp;
    return res;
}

void Stack::Push(int x){
    Node* p = new Node(x);
    this->size++;
    if(this->top == nullptr){
        this->top = p;
        return;
    }
    p->Set_next_node(this->top);
    this->top = p;
}