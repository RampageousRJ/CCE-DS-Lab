#include <iostream>
using namespace std;

class stk{
    int top;
    int arr[10];
public:
    stk(){
    top=-1;
    }

    void push();
    int pop();
    void display();
};

void stk::push(){
    if (top==9){
        cout<<"Stack Overflow Warning...";
        return;
    }
    int ele;
    cout<<"Enter element to be added: ";
    cin>>ele;
    arr[++top]=ele;
}

int stk::pop(){
    if (top==-1){
        cout<<"Stack Underflow Warning...";
        return -1;
    }
    return arr[top--];
}

void stk::display(){
    if (top==-1){
        cout<<"Empty Stack...";
        return;
    }
    cout<<"Contents of the stack are: \n";
    for(int i=0;i<top+1;i++){
        cout<<arr[i]<<"   ";
    }

}


int main(){
    stk s1;
    int n,ele;
    while(true){
        cout<<"\n\nMENU\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n";
        cout<<"Enter choice:";
        cin>>n;
        switch(n){
        case 1:
            s1.push();
            break;
        case 2:
            ele=s1.pop();
            cout<<ele<<" is the popped element...";
            break;
        case 3:
            s1.display();
        case 4:
            exit(0);
        default:
            cout<<"Invalid Operation...";
            exit(0);
        }
    }
return 0;
}
