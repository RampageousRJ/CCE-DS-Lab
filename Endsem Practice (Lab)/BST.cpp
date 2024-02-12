#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *left;
    Node *right;
    Node(int ele)
    {
        left = NULL;
        right = NULL;
        info = ele;
    }
};

Node* Insert(Node *root, int data)
{
    Node *temp=new Node(data);
    if (root == NULL)
    {
        return temp;
    }
    else if (data > root->info)
    {
        root->right=Insert(root->right, data);
    }
    else if(data < root->info)
    {
        root->left=Insert(root->left, data);
    }
    return root;
}

void Inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->info << "  ";
    Inorder(root->right);
}

void Search(Node *root,int ele){
    if(!root){
        cout<<"Not Found";
        return;
    }
    if(root->info==ele){
        cout<<"Element Found";
        return;
    }
    else if(root->info > ele){
        Search(root->left,ele);
    }
    else{
        Search(root->right,ele);
    }
}

int main()
{
    Node *root = NULL;
    int rootele;
    cout<<"Enter root value: ";
    cin>>rootele;
    root=Insert(root,rootele);
    Insert(root, 10);
    Insert(root, 20);
    Inorder(root);
    Search(root,20);
}