#include "AvlTree.h"
#include <iostream>
using namespace std;

AvlTree::AvlTree(){
    this->root = nullptr;
}

AvlTree::~AvlTree(){
    this->Delete(this->root);
}

void AvlTree::Delete(Node* p){
    if(p == nullptr) return;
    this->Delete(p->left);
    this->Delete(p->right);
    delete p;
}

int AvlTree::GetHeight(Node* p){
    if(p == nullptr) return 0;
    return p->height;
} 

int AvlTree::GetBalance(Node* p){
    if(p == nullptr) return 0;
    return GetHeight(p->left) - GetHeight(p->right);
}

bool AvlTree::Empty(){
    return this->root == nullptr;
}

bool AvlTree::Search(int x, Node* p){
    if(p == nullptr) return false;
    if(p->data == x) return true;
    return this->Search(x, p->left) || this->Search(x, p->right);

} 

bool AvlTree::Find(int x){
    return this->Search(x, this->root);
}

void AvlTree::Show(Node* p, int level){
    if(p == nullptr) return;

    Show(p->right, level+1);

    int space = 2 * level;
    for(int i = 0; i < 2*space; ++i){
        cout << " ";
    }
    cout << p->data << "(" << GetHeight(p) << ")" << endl;

    Show(p->left, level+1);
}

// Right-Right
Node* AvlTree::RotateLeft(Node* p){
    Node* k = p->right;
    p->right = k->left;
    k->left = p;

    // Updata Height
    p->height = 1 + max(GetHeight(p->left), GetHeight(p->right));
    k->height = 1 + max(GetHeight(k->left), GetHeight(k->right));

    return k;
}

// Left-Left
Node* AvlTree::RotateRight(Node* p){
    Node* k = p->left;
    p->left = k->right;
    k->right = p;

    // Update height
    p->height = 1 + max(GetHeight(p->left), GetHeight(p->right));
    k->height = 1 + max(GetHeight(k->left), GetHeight(k->right));

    return k;
}

// Private : Overload
Node* AvlTree::Insert(Node* p, int x){
    if(p == nullptr) return new Node(x);
    if(p->data == x){
        cout << "The value already exists" << endl;
        return p;
    }

    if(p->data > x) p->left = Insert(p->left, x);
    else p->right = Insert(p->right, x);

    p->height = 1 + max(GetHeight(p->left), GetHeight(p->right));

    int balance = GetBalance(p);
    if (balance > 1) {
        cout << "Node " << p->data << " is left-heavy\n";
        if(p->left->data > x){
            // Left-Left
            p = RotateRight(p);
        }
        else{
            // Left-Right
            p->left = RotateLeft(p->left);
            p = RotateRight(p);
        }
    }
    else if (balance < -1) {
        cout << "Node " << p->data << " is right-heavy\n";
        if(p->right->data < x){
            // Right-Right
            p = RotateLeft(p);
        }
        else{
            // Right-Left       
            p->right = RotateRight(p->right);
            p = RotateLeft(p);
        }
    }
    return p;
} 

Node* AvlTree::FindAncestor(Node* p){
    if(p == nullptr || p->right == nullptr) return nullptr;
    Node* k = p->right;
    while(k->left != nullptr) k = k->left;
    return k;
}

Node* AvlTree::FindFather(Node* r, Node* p){
    if(r == nullptr || p == nullptr) return nullptr;
    if(r->data == p->data) return nullptr; // p is root
    
    if(r->left == p || r->right == p) return r;

    if(r->data > p->data) return this->FindFather(r->left, p);
    else return this->FindFather(r->right, p);
}

// Private
Node* AvlTree::Remove(Node* p, int x){
    if(p == nullptr) return nullptr;
    if(p->data > x) p->left = Remove(p->left, x);
    else if(p->data < x) p->right = Remove(p->right, x);
    else{   // p->data == x

        // don't have a child 
        if(p->left == nullptr && p->right == nullptr){  
            delete p;
            return nullptr;
        }
        // has just one child 
        else if(p->left == nullptr || p->right == nullptr){
            if( p == this->root){
                if(p->left) this->root = p->left;
                if(p->right) this->root = p->right;
                delete p;
                return this->root;
            } 

            Node* child = (p->left != nullptr) ? p->left : p->right;
            delete p;
            return child;
        }
        // has two children 
        else{
            Node* An = FindAncestor(p);
            p->data = An->data;
            p->right = Remove(p->right, An->data);
        }
    }

    p->height = 1 + max(GetHeight(p->left), GetHeight(p->right));

    int balance = GetBalance(p);

    // Left - heavy 
    if(balance > 1){
        if(GetBalance(p->left) >= 0){ // Left - Left
            return RotateRight(p);
        }
        else{   // Left - Right
            p->left = RotateLeft(p->left);
            return RotateRight(p);
        }
    }

    // Right - heavy 
    else if(balance < -1){
        if(GetBalance(p->right) <= 0){
            // Right-Right
            return RotateLeft(p);
        }
        else{
            // Right-Left
            p->right = RotateRight(p->right);
            return RotateLeft(p);
        }
    }
    return p;
}

void AvlTree::Insert(int x){
    this->root = this->Insert(this->root, x);
}

void AvlTree::Remove(int x){
    this->root = this->Remove(this->root, x);
}

void AvlTree::Show(){
    this->Show(this->root, 0);
}
