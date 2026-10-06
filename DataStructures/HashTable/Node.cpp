#include "Node.h"

Node::Node(int x, Node* p) : data(x), next(p){

}

void Node::Set_data(int x){
    this->data = x;
}

int Node::Get_data(){
    return this->data;
}

Node* Node::Get_next_node(){
    return this->next;
}

void Node::Set_next_node(Node* p){
    this->next = p;
}