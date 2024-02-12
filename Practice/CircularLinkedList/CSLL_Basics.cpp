#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
    public:
    int info;
    Node *next;
};

Node* InsertStart(Node *head){
    Node *temp=new Node();
    Node *t=head;
    cout<<"Enter element to be added: ";
    cin>>temp->info;
    if(head==NULL){
        temp->next=temp;
        head=temp;
        return head;
    }
    while(t->next != head){
        t=t->next;
    }
    t->next=temp;
    temp->next=head;
    head=temp;
    return head;
}

Node* InsertEnd(Node *head){
    Node *temp=new Node();
    Node *t=head;
    cout<<"Enter element to be added: ";
    cin>>temp->info;
    if(head==NULL){
        head=temp;
        temp->next=temp;
        return head;
    }
    while(t->next != head){
        t=t->next;
    }
    t->next=temp;
    temp->next=head;
    return head;
}

void disp(Node *head)
{
    Node *t = head;
    for (; t->next!=head; t = t->next)
    {
        cout << t->info << "->";
    }
    cout<<t->info<<"->";
}

int main(){
    Node *head;
    head=NULL;
    head=InsertEnd(head);
    head=InsertEnd(head);
    head=InsertEnd(head);
    head=InsertEnd(head);
    head=InsertEnd(head);

    disp(head);

    return 0;
}