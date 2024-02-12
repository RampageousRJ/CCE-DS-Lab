#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
    Node(int ele)
    {
        info = ele;
        next = NULL;
    }
};

class que
{
    Node *front;
    Node *rear;
    public:
    que()
    {
        front = NULL;
        rear = NULL;
    }
    void enq(int ele)
    {
        Node *temp = new Node(ele);
        if(front==NULL){
            front=temp;
            rear=temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue Empty...";
            return;
        }
        Node *t=front;
        front=front->next;
        delete t;
    }

    int peek(){
        if(front==NULL){
            cout<<"Queue Empty...";
            return -1;
        }
        return front->info;
    }

    bool isEmpty(){
        if (!front){
            return true;
        }
        return false;
    }

    void disp(){
        while(!isEmpty()){
            cout<<peek()<<' ';
            pop();
        }
    }
};

int main(){
    que q;
    q.enq(1);
    q.enq(2);
    q.enq(3);
    q.enq(4);
    q.enq(5);
    q.disp();
    // cout<<q.peek();
}