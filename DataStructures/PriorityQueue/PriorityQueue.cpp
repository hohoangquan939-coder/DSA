#include "PriorityQueue.h"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue(){}

PriorityQueue::~PriorityQueue(){}

int PriorityQueue::Top(){
    if(this->heap.empty()){
        cout << "Priority Queue is empty" << endl;
        return -1;
    } 
    return this->heap[0];
}

bool PriorityQueue::Empty(){
    return this->heap.empty();
}

int PriorityQueue::Size(){
    return this->heap.size();
}

void PriorityQueue::Show(){
    if(this->heap.empty()){
        cout << "Queue is empty" << endl;
        return;
    }
    
    for(int i = 0; i < this->heap.size(); ++i){
        cout << this->heap[i] << " " ;
    }
    cout << endl;
}


void PriorityQueue::Push(int x){
    int index = 0;
    while(index < this->heap.size() && x <= this->heap[index]){
        index++;
    }
    this->heap.insert(this->heap.begin() + index, x);
}

void PriorityQueue::Pop(){
    if(this->heap.empty()){
        cout << "Priority Queue is empty" << endl;
        return;
    }
    this->heap.erase(this->heap.begin());
}