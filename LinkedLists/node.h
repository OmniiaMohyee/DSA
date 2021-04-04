class Node{

    
    Node* next;
    int data;

public:
    Node* getNext(){
        return this->next;

    }

    void setNext(Node* next){
        this->next = next;
    }

    int getData(){
        return this->data;
    }

    void setData(int data){
        this->data = data;
    }
};