#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *lcl, *rcl;
    Node(int elem){
        data=elem;
        lcl=rcl=NULL;
    }
};

Node* insert(Node *root,int elem){
    if(root==NULL)
        return new Node(elem);       
    if(elem>root->data)
        root->rcl=insert(root->rcl,elem);
    else
        root->lcl=insert(root->lcl,elem);
}


Node* search(Node *root, int elem){
    if(root==NULL||root->data==elem)
        return root;
    else if(root->data<elem)
        return search(root->rcl, elem);
    else
        return search(root->lcl,elem);
}

void inorder(Node *root){ 
    if(!root) 
        return;
    inorder(root->lcl); 
    cout<<root->data<<" "; 
    inorder(root->rcl);
}

Node* deleteNode(Node* root, int elem){
    if(root==NULL)
        return root;
    if(elem>root->data)
        root->rcl=deleteNode(root->rcl,elem);
    else if(elem<root->data)
        root->lcl=deleteNode(root->lcl,elem);
    else{
        Node *temp;
        if(root->lcl==NULL){
            temp=root->rcl;
            delete root;
            return temp;
        }
        else if(root->rcl==NULL){
            temp= root->lcl;
            delete root;
            return temp;
        }
        else{
            temp=root;
            while(temp && temp->lcl){
                temp=temp->lcl;
            }
            root->data=temp->data;
            root->rcl=deleteNode(root->rcl, temp->data);
        }
    }
}


int main(){
    Node *root=NULL;
    root=insert(root,30);
    int n, choice;
    cout<<"1. Insert an element "<<endl;
    cout<<"2. Delete an element "<<endl;
    cout<<"3. Search an element "<<endl;
    cout<<"4. Print the array "<<endl;
    while(true){
        cout<<">";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element:";
                cin>>n;
                insert(root,n);
                break;
            case 2:
                cout<<"Enter element:";
                cin>>n;
                deleteNode(root,n);
                break;
            case 3:     
                cout<<"Enter element:";
                cin>>n;
                search(root,n)?cout<<"Yes"<<endl:cout<<"NO"<<endl;
                break;
            case 4:
                inorder(root);
                cout<<endl; 
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
                return 0;
        }
    }
}