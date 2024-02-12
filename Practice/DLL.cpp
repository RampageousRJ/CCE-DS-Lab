#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
    Node *prev;
    Node(){
        info=0;
        next=NULL;
        prev=NULL;
    }
};

Node* ins(Node *head)
{
    Node *temp = new Node();
    cout << "Enter value to be inserted: ";
    cin>>temp->info;
    if (head == NULL)
    {
        return temp;
    }
    Node *t;
    t= head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
    temp->prev=t;
    return head;
}

void disp(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List";
    }
    Node *t = head;
    while (t->next != NULL)
    {   
        t=t->next;
    }
    while (t != NULL)
    {
        cout << t->info << "->";
        t=t->prev;
    }
}

int main()
{
    Node *head=NULL;
    head = ins(head);
    head = ins(head);
    head = ins(head);
    head = ins(head);
    disp(head);
    return 0;
}