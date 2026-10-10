#include "Node.h"

Node::Node(int x) : data(x){
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}

