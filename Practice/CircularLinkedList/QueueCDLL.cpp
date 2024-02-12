#include <iostream>
using namespace std;

class Node{
    public:
    int info;
    Node *next;
    Node *prev;
    Node(int ele){
        info=ele;
        this->next=this;
        this->prev=this;
    }
};

class que{
    Node *f, *r;
    Node *head=new Node;
};