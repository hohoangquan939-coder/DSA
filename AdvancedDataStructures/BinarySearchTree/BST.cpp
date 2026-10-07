#include "BST.h"
#include <iostream>
using namespace std;

BST::BST(){
    this->size = 0;
    this->root = nullptr;
}

BST::~BST(){
    this->DeleteTree(root);
    this->size = 0;
    this->root = nullptr;
}

void BST::DeleteTree(Node* head){
    if(head != nullptr){
        if(head->left) this->DeleteTree(head->left);
        if(head->right) this->DeleteTree(head->right);
        delete head;
    }
}

int BST::Size(){
    return this->size;
}

bool BST::Empty(){
    return this->size == 0;
}

void BST::Preorder(Node* p){
    if(p == nullptr) return;
    cout << p->data << " ";
    
    Preorder(p->left);
    Preorder(p->right);
}

void BST::Inorder(Node* p){
    if(p == nullptr) return;
    
    Inorder(p->left);
    cout << p->data << " ";
    Inorder(p->right);
}

void BST::Postorder(Node* p){
    if(p == nullptr) return;
    
    Postorder(p->left);
    Postorder(p->right);
    cout << p->data << " ";
}

void BST::Preorder_Show(){
    cout << "Preorder: ";
    this->Preorder(this->root);
    cout << endl;
}

void BST::Inorder_Show(){
    cout << "Ineorder: ";
    this->Inorder(this->root);
    cout << endl;
}

void BST::Postorder_Show(){
    cout << "Postorder: ";
    this->Postorder(this->root);
    cout << endl;
}

Node* BST::FindNodeInsert(int x, Node* p){
    if(p == nullptr || p->data == x){
       return p;
    }

    if(x > p->data){
        if(p->right != nullptr) return this->FindNodeInsert(x, p->right);
        return p;
    }
    else{
        if(p->left != nullptr) return this->FindNodeInsert(x, p->left);
        return p;
    }
}

void BST::Insert(int x){

    if(this->root == nullptr){      
        Node* p = new Node(x);
        this->root = p;
        this->size = 1;
        return;
    }

    Node* find = this->FindNodeInsert(x, this->root);
    if(find->data == x){
        cout << "Value already exists" << endl;
        return;
    }

    Node* p = new Node(x);
    if(find->data > x)  find->left = p;
    else    find->right = p;    
    this->size++;
}

Node* BST::FindFather(Node* p, int x){
    if(p == nullptr) return nullptr;

    if(p->left && p->left->data == x) return p;
    if(p->right && p->right->data == x) return p; 

    if(p->data > x) return FindFather(p->left, x);
    else return FindFather(p->right, x);
}   

Node* BST::Search_node(Node* p, int x){
    if(p == nullptr) return nullptr;

    if(p->data == x) return p;
    else if(p->data > x) return Search_node(p->left, x);
    else return Search_node(p->right, x);
}

bool BST::Search(int x){
    Node* p = Search_node(this->root, x);
    return p != nullptr;
}

Node* BST::FindInorderSuccessor(Node* p){
    if(p == nullptr || p->right == nullptr) return nullptr;
    
    Node* k = p->right;
    while(k->left != nullptr){
        k = k->left;
    }
    return k;
}

void BST::Delete(int x){
    Node* del = Search_node(this->root, x);

    if(del == nullptr){
        cout << "The value doesn't exist" << endl;
        return;
    }

    if(del->right == nullptr && del->left == nullptr){
        if(del == this->root){
            delete del;
            this->root = nullptr;
            this->size = 0;
            return;
        }

        Node* fa = FindFather(this->root, del->data);
        if(fa->right == del) fa->right = nullptr;
        if(fa->left == del) fa->left = nullptr;
        this->size--;
        delete del;
    }

    else if(del->right == nullptr || del->left == nullptr){
        this->size--;
        if(del == this->root){
            if(del->left) this->root = del->left;
            else this->root = del->right;
            delete del;
        }
        else {
            Node* fadel = FindFather(this->root, del->data);

            Node* child;

            if(del->left)   child = del->left;
            else    child = del->right;

            if(fadel->left == del)  fadel->left = child;
            else    fadel->right = child;

            delete del;
        }
    }

    else{
        this->size--;
        Node* successor = FindInorderSuccessor(del);
        Node* fasuc = FindFather(this->root, successor->data);
        del->data = successor->data;
        if(fasuc->right == successor) fasuc->right = successor->right;
        if(fasuc->left == successor) fasuc->left = successor->right;
        delete successor; 
    }
}
