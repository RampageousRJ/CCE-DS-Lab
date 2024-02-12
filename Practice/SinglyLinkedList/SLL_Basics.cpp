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
    cout << "\n\nEnter element to be inserted: ";
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
    Node *t;
    t = head;
    for (; t; t = t->next)
    {
        cout << t->info << "->";
    }
}

Node *deleteLast(Node *head)
{
    Node *t;
    Node *cur = new Node;
    cur = head;
    t = head;
    if (t == NULL)
    {
        cout << "Empty List";
        return head;
    }
    if (t->next == NULL)
    {
        delete head;
        head = NULL;
        return head;
    }
    while (t->next->next != NULL)
    {
        t = t->next;
    }
    delete t->next;
    t->next = NULL;
    return head;
}

Node *insertBefore(Node *head, int data)
{
    Node *temp = new Node();
    Node *t = head;
    Node *prev;
    cout << "Enter element to be inserted: ";
    cin >> temp->info;
    temp->next = NULL;
    if (head == NULL)
    {
        cout << "Empty List";
        return head;
    }
    if (head->info == data)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    while (t != NULL && t->info != data)
    {
        prev = t;
        t = t->next;
    }

    if (t == NULL)
    {
        cout << "Element not found...";
        return head;
    }
    temp->next = t;
    prev->next = temp;
    return head;
}

Node *deleteFirst(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Empty List";
        return head;
    }
    head = head->next;
    delete temp;
    return head;
}

Node *deleteAlternate(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Empty List...";
        return head;
    }
    Node *temp1 = temp->next;
    if (!temp1)
    {
        cout << "Only one element...";
        return head;
    }
    while (temp && temp1)
    {
        temp->next = temp1->next;
        delete temp1;
        temp = temp->next;
        if (temp)
        {
            temp1 = temp->next;
        }
    }
    return head;
}

Node *insertAfter(Node *head, int data)
{
    Node *temp = new Node();
    Node *t = head;
    cout << "Enter value to be inserted: ";
    cin >> temp->info;
    temp->next = NULL;
    if (head == NULL)
    {
        return temp;
    }
    if (head->info == data)
    {
        head->next = temp;
        return head;
    }
    while (t != NULL && t->info != data)
    {
        t = t->next;
    }
    if (t == NULL)
    {
        cout << "Element not found";
        return head;
    }
    temp->next = t->next;
    t->next = temp;
    return head;
}

Node* insertStart(Node* head){
    Node *temp=new Node;
    cout<<"Enter element to be added: ";
    cin>>temp->info;
    temp->next=NULL;
    if(head==NULL){
        return temp;
    }
    temp->next=head;
    head=temp;
    return head;
}

int main()
{
    Node *head=NULL;
    int res, elem;
    while (true)
    {
        cout << "\n\n1.Insert\n2.Display\n3.DeleteLast\n4.DeleteAlternate\n5.InsertBefore\n6.InsertAfter\n7.DeleteFirst\n8.InsertStart\n9.Exit\nEnter your choice: ";
        cin >> res;
        if (res == 1)
        {
            head = AddElement(head);
        }
        else if (res == 2)
        {
            disp(head);
        }
        else if (res == 3)
        {
            head = deleteLast(head);
        }
        else if (res == 4)
        {
            head = deleteAlternate(head);
        }
        else if (res == 5)
        {
            cout << "\nEnter element before which to insert: ";
            cin >> elem;
            head = insertBefore(head, elem);
        }
        else if (res == 7)
        {
            head = deleteFirst(head);
        }
        else if (res == 6)
        {
            cout << "\nEnter element after which to insert: ";
            cin >> elem;
            head = insertAfter(head, elem);
        }
        else if(res==8){
            head=insertStart(head);
        }
        else
        {
            break;
        }
    }

    return 0;
}