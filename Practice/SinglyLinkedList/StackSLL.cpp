#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
    public:
    int info;
    Node *next;
    Node* push(Node*);
    Node* pop(Node*);
    void disp(Node*);
};

Node* Node::push(Node *head){
    Node *temp=new Node;
    Node *t=head;
    cout<<"Enter element to be pushed: ";
    cin>>temp->info;
    temp->next=NULL;
    if(head==NULL){
        return temp;
    }
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp;
    return head;
}

Node* Node::pop(Node *head){
    if (head==NULL){
        cout<<"Enpty list";
        return head;
    }
    Node *t=head;
    if (t->next==NULL){
        delete t;
        head=NULL;
        return head;
    }
    while(t->next->next != NULL){
        t=t->next;
    }
    delete t->next;
    t->next=NULL;
    return head;
}

void Node::disp(Node *head){
    Node *t=head;
    for(;t;t=t->next){
        cout<<t->info<<"->";
    }    
}

int main(){
    Node *head=NULL;
    Node n;
    int res;
    while(true){
        cout<<"\n\nMENU\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ";
        cin>>res;
        if(res==1){
            head=n.push(head);
        }
        else if(res==2){
            head=n.pop(head);
        }
        else if(res==3){
            n.disp(head);
        }
        else{
            return 0;
        }
    }
return 0;
}