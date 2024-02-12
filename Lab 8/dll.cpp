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

Node *delRear(Node* head){
    if(head==NULL){
        cout<<"Empty List...";
        return head;
    }
    Node *t=head;
    while(t->next!=NULL){
            t=t->next;
    }
    t->prev->next=NULL;
    delete t;
    return head;
}


int countNodes(Node *head){
    if (head==NULL){
        return 0;
    }
    int cnt=1;
    Node *t=head;
    for(;t;t=t->next){
        cnt++;
    }
    return cnt;
}

Node *insAtPos(Node *head){
    cout<<"Enter element to insert: ";
    int ele,cnt=1,pos;
    cin>>ele;
    cout<<"Enter position: ";
    cin>>pos;
    Node *temp=new Node(ele);
    if(head==NULL){
        return temp;
    }
    Node *t=head;
    if(pos==1){
        t->prev=temp;
        temp->next=t;
        head=temp;
        return head;
    }
    if(pos==countNodes(head)){
        head=insRear(head);
        return head;
    }
    while(cnt!=pos){
        t=t->next;
        cnt++;
        if(t==NULL){
            cout<<"Position does not exist";
            return head;
        }
    }
    temp->next=t;
    temp->prev=t->prev;
    t->prev->next=temp;
    t->prev=temp;
    return head;
}

Node *delAtPos(Node *head){
    int pos,cnt=1;
    cout<<"Enter position: ";
    cin>>pos;
    if(head==NULL){
        cout<<"Empty List...";
        return head;
    }
    Node *t=head;
    if(pos==1){
        head=t->next;
        delete t;
        return head;
    }
    if(pos==countNodes(head)){
        head=delRear(head);
        return head;
    }
    while(cnt!=pos){
        t=t->next;
        cnt++;
        if(t==NULL){
            cout<<"Position does not exist";
            return head;
        }
    }
    t->prev->next=t->next;
    t->next->prev=t->prev;
    delete t;
    return head;
}

Node *insBefore(Node *head){
    int ele,elembef;
    cout<<"Enter element and before which: ";
    cin>>ele>>elembef;
    Node *temp=new Node(ele);
    if(head==NULL){
        return temp;
    }
    Node *t=head;
    while(t->info != elembef){
        if(t==NULL){
            cout<<"Element not found";
            return head;
        }
        t=t->next;
    }
    temp->next=t;
    temp->prev=t->prev;
    t->prev->next=temp;
    t->prev=temp;
    return head;
}

Node *insAfter(Node *head){
    int ele,elemaft;
    cout<<"Enter element and before which: ";
    cin>>ele>>elemaft;
    Node *temp=new Node(ele);
    if(head==NULL){
        return temp;
    }
    Node *t=head;
    while(t->info != elemaft){
        if(t==NULL){
            cout<<"Element not found";
            return head;
        }
        t=t->next;
    }
    temp->prev=t;
    temp->next=t->next;
    t->next->prev=temp;
    t->next=temp;
    return head;
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

Node *rev(Node *head){
    Node *h=head,*t=head;
    int temp;
    while(t->next!=NULL){
        t=t->next;
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

int main(){
    Node *head=NULL;
    int res;
    cout<<"MENU\n1.InsertFromRear\n2.DeleteFromRear\n3.InsertAtPos\n4.DeleteAtPos\n5.InsertAfter\n6.InsertBefore\n7.Display\n8.Reverse\n";
    while(true){
        cout<<"\nEnter your choice: ";
        cin>>res;
        if(res==1){
            head=insRear(head);
        }
        else if(res==2){
            head=delRear(head);
        }
        else if(res==3){
            head=insAtPos(head);
        }
        else if(res==4){
            head=delAtPos(head);
        }
        else if(res==5){
            head=insAfter(head);
        }
        else if(res==6){
            head=insBefore(head);
        }
        else if(res==7){
            disp(head);
        }
        else if(res==8){
            head=rev(head);
        }
        else{
            break;
        }
    }
return 0;
}
