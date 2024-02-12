#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
    // Node(int data){
    //     info=data;
    //     next=NULL;
    // }
};

Node *AddElement(Node *head)
    {
        Node *temp = new Node;
        Node *t;
        int ele;
        cout << "\n\nEnter element to be inserted: ";
        cin >> ele;
        temp->info=ele;
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
        t->next=temp;
        return head;
    }

    Node* disp(Node *head){
        Node *t;
        t=head;
        for(;t;t->next){
            cout<<t->info<<"->";
        }
        return head;
    }

int main()
{
    Node *head;
    int res;
    while(true){
        cout<<"\n\n1.Insert\n2.Display\n3.Exit\nEnter your choice: ";
        cin>>res;
        if (res==1){
            AddElement(head);
        }
        else if(res==2){
            disp(head);
        }
        else{
            break;
        }
    }

    return 0;
}
