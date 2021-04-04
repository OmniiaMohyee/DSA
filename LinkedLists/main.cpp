#include<iostream>
using namespace std;
#include "linkedList.h"
#include "node.h"

//Q11
Node* alternateMerge(LinkedList* L1, LinkedList* L2){
    if(L1->getHead() == nullptr) return L2->getHead();
    else if(L2->getHead() == nullptr) return L1->getHead();

    Node* ptr1 = L1->getHead(); 
    Node* ptr2 = L2->getHead();
    Node* new_head;

    Node* ptr = ptr1;
    ptr1 = ptr1->getNext();
    new_head = ptr;
    int i = 1;
    while(ptr1 != nullptr && ptr2 != nullptr){
        if(i%2){
            ptr->setNext(ptr2);
            ptr2 = ptr2->getNext();

        }
        else{
            ptr->setNext(ptr1);
            ptr1 = ptr1->getNext();
        }
        ptr = ptr->getNext();
        i++;

    }
    return new_head;
}

int main(){

    

}