 #include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=this;
        this->prev=this;
    }
};

Node* insertEle(Node* head)
{
    cout<<"Enter the value to be inserted: "<<endl;
    int n;
    cin>>n;
    Node* newNode=new Node(n);
    if(head == NULL){
        return newNode;
    }
    Node* temp=head->prev;
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=head;
    head->prev=newNode;
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

void del(Node* head, int ele){
    Node *temp=head;
    while(temp->data != ele){
        if(temp->next == NULL){
            cout<<"Element not found "<<endl;
            return;
        }
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
}

int main()
{
    int ele, pos;
    Node *head = NULL;
    char choice='y';
    cout<<"Enter element"<<endl;
    while(choice != 'n'){
        head=insertEle(head);
        cout<<"Enter n to stop the list, y to continue"<<endl;
        cin>>choice;
    }
    int n=0;
    while (n != -1)
    {
        switch (n)
        {
        case 1:
            head = insertEle(head);
            break;
        case 2:
            cout<<"Enter the element to be deleted: "<<endl;
            cin>>pos;
            del(head,pos);
            break;
        case 3:
            print(head);
            break;
        }
        cout << "1. Insert \n2. Delete \n3. Print \n-1. Terminate" << endl;
        cin >> n;
    }
}