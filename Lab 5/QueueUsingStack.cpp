// Program to implement queue using Stack
#include <iostream>
using namespace std;
const int n=3;

class Stack{
    private:
    int arr[n];
    int top;
    public:
    Stack(){
        top=-1;}

    bool isEmpty(){
        return (top==-1);}

    bool isFull(){
        return (top+1==n);}

    void push(int elem){
        if(!isFull()){
            arr[++top]=elem;}
        }

    int pop(){
        if(!isEmpty()){
            return arr[top--];
        }
    }

    int peek(){
        if(!isEmpty()){
            return arr[top];
        }
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

class Queue{
    private:
    Stack s1,s2;
    public:
    void enq(int elem){
        if(s1.isEmpty()){
            s1.push(elem);
        }
        else{
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
            s1.push(elem);
            while(!s2.isEmpty()){
                s1.push(s2.pop());
            }
        }
    }
    int deq(){
        return s1.pop();
    }

    void disp(){
        s1.display();
    }
};

int main(){
    Queue q;
    while(true){
        cout<<"\n\nMENU\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice:";
        int ch,ele;
        cin>>ch;
        if (ch==1){
            cout<<"Enter element: ";
            cin>>ele;
            q.enq(ele);
        }
        else if(ch==2){
            q.deq();
        }
        else if(ch==3){
            q.disp();
        }
        else{
            break;
        }
    }
}
