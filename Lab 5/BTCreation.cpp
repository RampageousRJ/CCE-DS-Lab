#include <iostream>
using namespace std;
class Node
{
public:
    int info;
    Node *lcl;
    Node *rcl;
};
class Tree
{   
    public:
    Node *root;
    Tree()
    {
        root = createBT();
    }
    Node *createBT()
    {
        int ele;
        cout << "Enter Element: ";
        cin >> ele;
        if (ele == -1)
        {
            return root;
        }
        Node *temp=new Node();
        temp->info=ele;
        cout << "Enter left of " << ele<<": ";
        temp->lcl=createBT();
        cout << "Enter right of " << ele<<": ";
        temp->rcl=createBT();
    }

    void display(Node *root,int level){
        int i;
        if(!root){
            return;
        }
        display(root->rcl,level+1);
        for(int i=0;i<level;i++){
            cout<<"    ";
        }
        cout<<root->info<<endl;
        display(root->lcl,level+1);
    }
};

int main(){
    Tree t;
    t.display(t.root,1);
    return 0;
}