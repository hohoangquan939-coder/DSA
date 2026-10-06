#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int n, Node* ptr) : data(n), next(ptr){

}

Node::~Node(){
    this->next = nullptr;
}

int Node::get_data(){
    return this->data;
}

void Node::set_data(int x){
    this->data = x;
}

void Node::set_next_node(Node* p){
    this->next = p;
}

Node* Node::get_next_node(){
    return this->next;
}

