#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
    Node *prev;
    Node(int ele)
    {
        info = ele;
        this->next = this;
        this->prev = this;
    }
};

Node *insHead(Node *head)
{
    cout << "Enter element: ";
    int ele;
    cin >> ele;
    Node *temp = new Node(ele);
    if (head == NULL)
    {
        return temp;
    }
    Node *t = head;
    temp->next = t;
    temp->prev = t->prev;
    t->prev->next = temp;
    t->prev = temp;
    return temp;
}

void disp(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List...";
        return;
    }
    Node *t = head;
    for (; t->next != head; t = t->next)
    {
        cout << t->info << "->";
    }
    cout << t->info << "->";
}

Node *insTail(Node *head)
{
    cout << "Enter element: ";
    int ele;
    cin >> ele;
    Node *temp = new Node(ele);
    if (head == NULL)
    {
        return temp;
    }
    Node *t = head->prev;
    temp->prev = t;
    temp->next = t->next;
    t->next->prev = temp;
    t->next = temp;
    return head;
}

Node *delHead(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List...";
        return head;
    }
    Node *t = head;
    head = t->next;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
    return head;
}

Node *delTail(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List...";
        return head;
    }
    Node *t = head->prev;
    t->prev->next=t->next;
    t->next->prev=t->prev;
    delete t;
    return head;
}

Node *rev(Node *head){
    int temp;
    Node *h=head,*t=head->prev;
    if(head==NULL){
        cout<<"Empty List";
        return head;
    }
    while(h!=t && h->next!=t){
        temp=h->info;
        h->info=t->info;
        t->info=temp;
        h=h->next;
        t=t->prev;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    char res = 'y';
    while (res == 'y')
    {
        cout << "\n\nMENU\n1.InsertHead\n2.Display\n3.InsertTail\n4.DeleteHead\n5.DeleteTail\n6.Reverse\n";
        int ch;
        cout << "\nEnter your choice: ";
        cin >> ch;
        if (ch == 1)
        {
            head = insHead(head);
        }
        else if (ch == 2)
        {
            disp(head);
        }
        else if (ch == 3)
        {
            head = insTail(head);
        }
        else if (ch == 4)
        {
            head = delHead(head);
        }
        else if (ch == 5)
        {
            head = delTail(head);
        }
        else if(ch==6){
            head=rev(head);
        }
        else
        {
            break;
        }
    }
    return 0;
}