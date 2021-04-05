#pragma once

#include "node.h"
#include<iostream>
using namespace std;
class LinkedList{
    Node* head;
    
public:
    LinkedList(){
        head = nullptr;
    }

    Node* getHead(){
        return this->head;
    }

    void setHead(Node* head){
        this->head = head;

    }  
    
    int getCount(){
        int count = 0;
        Node* ptr = head;
        while(ptr != nullptr)
        {
            count++;
            ptr = ptr->getNext();
        }
        return count;

    }

    void insertAtBegin(int data){
        Node* new_node = new Node;
        new_node->setData(data);

        new_node->setNext(this->head);
        this->head = new_node;        
    }

    void traverse(){
        Node* ptr = head;
        while(ptr != nullptr)
        {
            cout<<ptr->getData()<<" ";
            ptr = ptr->getNext();
        }
        cout<<endl;

    }

    //Q1: count negative elements in a list;
    int countNeg(){
        int count = 0;
        Node* ptr = head;
        while(ptr != nullptr)
        {
            if(ptr->getData() <0)
                count++;
            ptr = ptr->getNext();
        }
        return count;

    }

    //Q2: get Min element in a linked list.
    int getMin(){
        int min = -1;
        if(this->head != nullptr)
            min = head->getData();

        Node* ptr = this->head;
        while(ptr != nullptr)
        {
            if(ptr->getData()<min)
                min = ptr->getData();
            ptr = ptr->getNext();
        }
        return min;

    }

    //Q3: Print Elements in positions given in LinkedList P
    // here the member list is the L and P will be sent as an argument to the function.
    void PrintLots(LinkedList* P){
        Node* pHead = P->getHead();
        Node* lHead = this->head;
        int i = 0; //index to be printed.
        while(pHead != nullptr){
            while(lHead != nullptr)
            {
                if(i == pHead->getData()){
                    cout<<"L["<<i<<"]: "<<lHead->getData()<<endl;
                    break;
                }
                i++;
                lHead = lHead->getNext();
            }
            pHead = pHead->getNext();

        }

    }

    void insertAfter(Node* prev, int data){
        if(prev == nullptr) return; //operation failed;
        Node* tmp = prev->getNext();
        Node* new_node = new Node;
        new_node->setData(data);
        new_node->setNext(tmp);
        prev->setNext(new_node);
    }


    
    //Q4: given a linked list, insert elements to complete the list.
    //same as Q3, we will insert into the member list.
    void completeList(){
        if(this->head == nullptr) return;
        Node* slow= this->head;
        Node* fast= this->head->getNext();
        int i = slow->getData();
        i++;
        while(fast != nullptr){
            if(i != fast->getData())
                this->insertAfter(slow, i);
            i++;
            slow = slow->getNext();
            fast = slow->getNext();
        }
    }

    bool deleteHead(){
        if(this->head == nullptr) return false;
        Node* tmp = this->head;
        this->head = tmp->getNext();
        delete tmp;
        return true;
    }

    bool deleteAfter(Node* prev){

        if(prev == nullptr) return false;
        if(prev->getNext() == nullptr) return false;

        Node* tmp = prev->getNext();
        prev->setNext(tmp->getNext());
        delete tmp;

        return true;

    }

    Node* getTail(){
        if(this->head == nullptr) return nullptr;
        Node* ptr = this->head;
        while(ptr->getNext() != nullptr)
            ptr = ptr->getNext();
        return ptr;
    }

    //Q5: traverse and delete All negatives
    void deleteAllNeg(){
        if(this->head == nullptr) return;

        //check if head contains negative data.
        while(this->head != nullptr && this->head->getData()<0)
            this->deleteHead();

        if(this->head == nullptr) return;

        
        Node* slow = this->head;
        Node* fast = slow->getNext();

        while(fast != nullptr){
            if(fast->getData() < 0)
                this->deleteAfter(slow);

            slow = slow->getNext();
            fast = slow->getNext();
        }
    }

    //Q6: append L to the list and clear L.
    void appendList(LinkedList* L){
        if(L->getHead() == nullptr) return;
        if(this->head == nullptr){
            this->head = L->getHead();
            L->setHead(nullptr);
        }
        else{
            Node* ptr = this->getTail();
            ptr->setNext(L->getHead());
            L->setHead(nullptr);
        } 
    }
    //Q7: append List to itself.
    void appendListToItself(){
        if(this->head == nullptr) return;
        LinkedList* L = new LinkedList;

        L->insertAtBegin(this->head->getData());
        Node* Lptr = L->getHead();
        Node* ptr = this->head->getNext();
        while(ptr != nullptr){
            L->insertAfter(Lptr, ptr->getData());
            Lptr = Lptr->getNext();
            ptr = ptr->getNext();
        }
        this->appendList(L);
        delete L;   
    }

    Node* getAtIndex(int index){
        Node* ptr = this->head;
        int i = 0 ;

        while(ptr != nullptr){
            if(i == index) return ptr;
            i++;
        }
        return nullptr;
    }

    //Q8: swap two nodes, given 2 indices, the small index comes first.
    bool swapNode(int small, int large){

        //special case: we want to swap with the head.
        if(small == 0){
            Node* later = this->getAtIndex(large);
            if(later == nullptr) return false;
            if(later->getNext() == nullptr) return false;

            Node* tmp = later->getNext();
            Node* tmp2 = this->head->getNext();
            tmp->setNext(tmp2);
            later->setNext(this->head);
            this->head = tmp;       
            return true;     
        }
        else{
            Node* first = this->getAtIndex(small-1);
            Node* later = this->getAtIndex(large-1);

            if(first == nullptr || later == nullptr) return false;
            if(first->getNext() == nullptr || later->getNext() == nullptr) return false;

            


            Node* z = later->getNext();
            later->setNext(first->getNext());
            first->setNext(z);

            z = later->getNext()->getNext();
            later->getNext()->setNext(first->getNext()->getNext());
            first->getNext()->setNext(z);
  
        }
    }

    //Q9: mergeSortedList
    Node* MergeSorted(LinkedList* L){
        if(this->head == nullptr) return nullptr;
        if(L->getHead() == nullptr) return this->head;

        Node* iter;
        Node* ptr1 = this->head;
        Node* ptr2 = L->getHead();
        if( ptr1->getData() < ptr2->getData()){
            
            iter = ptr1;
            ptr1 = ptr1->getNext();

        }
        else{
            iter = ptr2;
            ptr2 = ptr2->getNext();

        }
        while(ptr1 != nullptr && ptr2 != nullptr){
            if( ptr1->getData() < ptr2->getData()){
            iter->setNext(ptr1);
            ptr1 = ptr1->getNext();

        }
        else{
            iter->setNext(ptr2);
            ptr2 = ptr2->getNext();

        }
        iter = iter->getNext();
        }
        if(ptr1 != nullptr)
            iter->setNext(ptr1);
        else
            iter->setNext(ptr2);

    }

    //Q10
    Node** alternateSplit()
    {
        if(this->head == nullptr) return nullptr;
        Node* ptr = head;
        Node* ptr2 = head->getNext();
        if(ptr2 == nullptr) return nullptr;
        int i = 0;
        Node* tmp = ptr2->getNext();
        while(tmp != nullptr)
        {
            if(i%2 == 0){
                ptr->setNext(tmp);
                ptr = ptr->getNext();
            }
            else{
                ptr2->setNext(tmp);
                ptr2 = ptr2->getNext();
            }

            tmp = tmp->getNext();
            // ptr = ptr->getNext();
            // ptr2 = ptr2->getNext();
            i++;

        }

        Node** ptrs = new Node*[2];
        ptrs[0] = head;
        ptrs[1] = head->getNext();
        return ptrs;
    }

    //Q11
    Node* Josephus(LinkedList* circ, int m){
        if(circ == nullptr) return nullptr;
        if(circ->getHead() == nullptr) return nullptr;

        Node* ptr = circ->getHead();
        Node* before;
        Node* temp;
        while(ptr != ptr->getNext())
        {
            for(int i = 0 ; i < m ; i++){
                before = ptr;
                ptr = ptr->getNext();
            }
            Node* tmp = ptr->getNext();
            delete ptr;
            before->setNext(tmp);
            ptr = tmp;
        }

    }
};