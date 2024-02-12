#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *lcl;
    Node *rcl;
    Node(int val){
        data = val;
        lcl=NULL;
        rcl=NULL;
    }
};

void preorder(Node *root){
    if (root){
    cout<<root->data;
    preorder(root->lcl);
    preorder(root->rcl);
    }
}

void inorder(Node *root){
    if (root){
    inorder(root->lcl);
    cout<<root->data;
    inorder(root->rcl);
    }
}

void postorder(Node *root){
    if (root){
    postorder(root->lcl);
    postorder(root->rcl);
    cout<<root->data;
    }
}

int main(){
    Node *root=new Node(1);
    root->lcl=new Node(2);
    root->rcl=new Node(3);

    root->lcl->lcl=new Node(4);
    root->lcl->rcl=new Node(5);

    root->rcl->lcl=new Node(6);
    root->rcl->rcl=new Node(7);

    cout<<"\nPreorder Traversal: ";
    preorder(root);

    cout<<endl<<endl<<"Inorder Traversal: ";
    inorder(root);
    
    cout<<endl<<endl<<"Postorder Traversal: ";
    postorder(root);

    return 0;
}