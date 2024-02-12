#include <iostream>
using namespace std;

class Node{
    public:
    int info;
    Node *next;
    Node *prev;
    Node(int ele){
    info=ele;
    next=NULL;
    prev=NULL;
    }
};

Node* insRear(Node *head){
    cout<<"Enter element to insert: ";
    int ele;
    cin>>ele;
    Node *temp=new Node(ele);
    if(head==NULL){
        return temp;
    }
    Node *t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp;
    temp->prev=t;
    return head;
}

Node *concat(Node *h1,Node *h2){
    Node *t=h1;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=h2;
    return h1;
}

void disp(Node *head){
    if (head==NULL){
        cout<<"Empty List";
        return;
    }
    Node *t=head;
    for(;t;t=t->next){
        cout<<t->info<<"->";
    }
}

int main(){
    Node *h1=NULL,*h2=NULL;
    char res='y';
    cout<<"Insert into first LL\n ";
    while(res=='y'){
        h1=insRear(h1);
        cout<<"Do you want more?(y/n)";
        cin>>res;
    }
    disp(h1);
    res='y';
    cout<<endl;
    cout<<"Insert into second LL\n ";
    while(res=='y'){
        h2=insRear(h2);
        cout<<"Do you want more?(y/n)";
        cin>>res;
    }
    disp(h2);
    cout<<endl;
    h1=concat(h1,h2);
    disp(h1);
return 0;
}
