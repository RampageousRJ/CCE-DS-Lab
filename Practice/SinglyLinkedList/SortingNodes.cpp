#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
};

Node *AddElement(Node *head)
{
    Node *temp = new Node;
    Node *t;
    int ele;
    cout << "\nEnter element to be inserted: ";
    cin >> ele;
    temp->info = ele;
    temp->next = NULL;
    if (head == NULL)
    {
        return temp;
    }
    t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
    return head;
}

void disp(Node *head)
{
    Node *t = head;
    for (; t; t = t->next)
    {
        cout << t->info << "->";
    }
}

Node *swapval(Node *head, int data)
{
    Node *t = head, *temp, *prev,*t1;
    while (t && t->info != data)
    {
        prev = t;
        t = t->next;
    }
    if (t == NULL)
    {
        cout << "Element not found...";
        return head;
    }
    t1=t->next;
    swap(t1->info,t->info);
    return head;
}

int countnodes(Node *head){
    int cnt;
    Node *t=head;
    for(;t;t=t->next){
        cnt++;
    }
    return cnt;
}

Node* bubblesort(Node *head){
    for(Node *t=head ; t ; t=t->next){
        for(Node *t2=t->next ; t2 ; t2=t2->next){
            if(t->info > t2->info){
                swap(t->info, t2->info);
            }
        }
    }
    return head;
}

Node* rev(Node *head){
    Node *prev=NULL,*cur=head,*nextptr;
    while(cur!=NULL){
        nextptr=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextptr;
    }
    return prev;
}

int main()
{
    Node *head = NULL;
    Node *revhead=NULL;
    // int val;
    head = AddElement(head);
    head = AddElement(head);
    head = AddElement(head);
    head = AddElement(head);
    head = AddElement(head);
    disp(head);
    // cout << "\n\nEnter value and after to be swapped: ";
    // cin >> val;
    // head = swapval(head, val);
    // disp(head);

    head=bubblesort(head);
    cout<<"\nAfter sorting: \n";
    disp(head);


    revhead=rev(head);
    cout<<"\nAfter reversing: \n";
    disp(revhead);
    return 0;
}