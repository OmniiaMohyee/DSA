#include<iostream>
using namespace std;
#include "linkedList.h"

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

    LinkedList* L = new LinkedList();
    L->insertAtBegin(7);
    L->insertAtBegin(5);
    L->insertAtBegin(2);
    L->insertAtBegin(-1);
    cout<<"The input linked list:"<<endl;
    L->traverse();

    // cout<<"Q1"<<endl;
    // cout<<L->countNeg()<<endl;
    // cout<<"Q2"<<endl;
    // cout<<L->getMin()<<endl;
    // cout<<"Q3"<<endl;
    LinkedList* L2 = new LinkedList();
    L2->insertAtBegin(2);
    L2->insertAtBegin(1);
    L2->insertAtBegin(0);
    // cout<<"P list is:";
    // L2->traverse();
    // L->PrintLots(L2);
    // cout<<"Q4"<<endl;
    // L->completeList();
    // L->traverse();
    // cout<<"Q5"<<endl;
    // L->deleteAllNeg();
    // L->traverse();
    // cout<<"Q6"<<endl;
    // L->appendList(L2);
    // L->traverse();
    // L2->traverse();
    // cout<<"Q7"<<endl;
    // L->appendListToItself();
    // L->traverse();

    // cout<<"Q8"<<endl;
    // L->swapNode(1,2);
    // L->traverse();
    cout<<"Q9"<<endl;
    L->MergeSorted(L2);
    L->traverse();

    cout<<"Q10"<<endl;
    Node** ptrs = L->alternateSplit();
    Node* ptr1 = ptrs[0];
    Node* ptr2 = ptrs[1];
    while(ptr1 != nullptr){
        cout<<ptr1->getData()<<" ";
        ptr1 = ptr1->getNext();
    }
    cout<<endl;
    while(ptr2 != nullptr){

    cout<<ptr2->getData()<<" ";
    ptr2 = ptr2->getNext();
    }
    cout<<endl;
    


    



    return 0;

    

}