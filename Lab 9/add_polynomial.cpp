#include<iostream> 
using namespace std; 

class Node{
    public:
    int coef;
    int pow;
    Node* next;
    Node* prev;
    Node(int data, int pow){
        this->pow=pow;
        this->coef=data;
        this->next=this;
        this->prev=this;
    }
};

Node* createPoly(Node* header,int co, int deg){
    Node* newNode=new Node(co,deg);
    if(header->next == NULL){
        header->next=newNode;
        newNode->next=header;
        header->prev=newNode;
        return header;
    }
    Node* temp=header->prev;
    temp->next=newNode;
    newNode->next=header;
    header->prev=newNode;
    return header;
}

void add(Node* header1, Node* header2, Node* fHeader){
    Node* temp1,*temp2,*temp3;
    int coef,deg;
    temp1=header1->next;
    temp2=header2->next;
    while(temp1 != header1 && temp2 != header2){
        if(temp1->pow == temp2->pow){
            coef=temp1->coef+temp2->coef;
            deg=temp1->pow;
            fHeader=createPoly(fHeader,coef,deg);
            temp1=temp1->next;
            temp2=temp2->next;
        } else if(temp1->pow > temp2->pow){
            coef=temp1->coef;
            deg=temp1->pow;
            fHeader=createPoly(fHeader,coef,deg);
            temp1=temp1->next;
        } else{
            coef=temp2->coef;
            deg=temp2->pow;
            fHeader=createPoly(fHeader,coef,deg);
            temp2=temp2->next;
        }
    }
    while(temp1 != header1){
        coef=temp1->coef;
        deg=temp1->pow;
        fHeader=createPoly(fHeader,coef,deg);
        temp1=temp1->next;
    }
    while(temp2 != header2){
        coef=temp2->coef;
        deg=temp2->pow;
        fHeader=createPoly(fHeader,coef,deg);
        temp2=temp2->next;
    }
}

void display(Node* header){
    Node* temp=header->next;
    while(temp->next != header){
        cout<<temp->coef<<"X^"<<temp->pow<<"+";
        temp=temp->next;
    }
    cout<<temp->coef<<"X^"<<temp->pow<<endl;
}
int main(){ 
    Node* header1=new Node(0,0);
    char choice='y';
    cout<<"Create polynomial 1"<<endl;
    while(choice != 'n'){
        int co,deg;
        cout<<"Enter the coef of the polynomial: ";
        cin>>co;
        cout<<"Enter the degree of the term: ";
        cin>>deg;
        header1=createPoly(header1,co,deg);
        cout<<"Enter n to stop and y to continue"<<endl;
        cin>>choice;
    }
    choice='y';
    cout<<"Polynomial 1 is"<<endl;
    display(header1);
    Node* header2=new Node(0,0);
    cout<<"Create polynomial 2"<<endl;
    while(choice != 'n'){
        int co,deg;
        cout<<"Enter the coef of the polynomial: ";
        cin>>co;
        cout<<"Enter the degree of the term: ";
        cin>>deg;
        header2=createPoly(header2,co,deg);
        cout<<"Enter n to stop and y to continue"<<endl;
        cin>>choice;
    }
    cout<<"Polynomial 2 is"<<endl;
    display(header2);
    Node* fheader=new Node(0,0);
    add(header1,header2,fheader);
    cout<<"Polynomial after addition is: "<<endl;
    display(fheader);
    return 0;
}