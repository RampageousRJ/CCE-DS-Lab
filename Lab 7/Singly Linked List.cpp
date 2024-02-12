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

Node *deleteGiven(Node *head, int ele)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Empty List";
        return head;
    }
    Node *t = head, *p;
    while (t->info != ele)
    {
        p = t;
        t = t->next;
    }
    if (t->info == ele)
    {
        p->next = t->next;
        delete t;
    }
    else
    {
        cout << "Element not found...";
    }
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

Node *rev(Node *head)
{
    Node *prev = NULL, *cur = head, *nextptr;
    while (cur != NULL)
    {
        nextptr = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextptr;
    }
    return prev;
}

int countnodes(Node *head)
{
    int cnt=0;
    Node *t = head;
    for (; t; t = t->next)
    {
        cnt++;
    }
    return cnt;
}

Node *bubblesort(Node *head)
{
    int cnt = countnodes(head), temp;
    Node *t = head;
    Node *t1;
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (t->info > t->next->info)
            {
                temp = t->info;
                t->info = t->next->info;
                t->next->info = temp;
            }
            t = t->next;
        }
        t = head;
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

void insert_sort(Node *head,int ele){
        Node *temp=new Node;
        Node *trav=head;
        temp->info=ele;
        //EDGE CASE:List Empty
        if(head==NULL){
            head=AddElement(head);
            return;
        }
        if(trav->info>ele){
            temp->next=head;
            head=temp;
            return;
        }
        while(trav->next!=NULL){
            if(trav->next->info>ele){
                temp->next=trav->next;
                trav->next=temp;
                break;
            }
            trav=trav->next;
        }
        if(trav->next==NULL){
            trav->next=temp;
            temp->next=NULL;
        }
    }

int main()
{
    Node *head = NULL;
    int res, elem;
    cout << "MENU\n\n1.Insert\n2.InsertBefore\n3.InsertAfter\n4.DeleteGiven\n5.Display\n6.Reverse\n7.Sort\n8.DeleteAlternate\n9.InsertSorted\n10.Exit\n";
    while (true)
    {
        cout << "\nEnter your choice: ";
        cin >> res;
        if (res == 1)
        {
            head = AddElement(head);
        }
        else if (res == 2)
        {
            cout << "\nEnter element before which to insert: ";
            cin >> elem;
            head = insertBefore(head, elem);
        }
        else if (res == 3)
        {
            cout << "\nEnter element after which to insert: ";
            cin >> elem;
            head = insertAfter(head, elem);
        }
        else if (res == 4)
        {
            cout << "Enter element to be deleted: ";
            cin >> elem;
            head = deleteGiven(head, elem);
        }
        else if (res == 5)
        {
            disp(head);
        }
        else if (res == 6)
        {
            head = rev(head);
        }
        else if (res == 7)
        {
            head = bubblesort(head);
        }
        else if (res == 8)
        {
            head = deleteAlternate(head);
        }
        else if(res==9){
            insert_sort(head,elem);
        }
        else
        {
            break;
        }
    }

    return 0;
}