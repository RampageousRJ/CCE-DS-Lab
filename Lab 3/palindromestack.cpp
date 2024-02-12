#include <iostream>
using namespace std;

class stk{
    int top;
    int arr[10];

public:
    stk(){
    top=-1;
    }
    void push(int);
    int pop();
    void display();
};

void stk::push(int ele){
    if (top==9){
        exit(0);
    }
    arr[++top]=ele;
    return;
}

int stk::pop(){
    if (top==-1){
        return -1;
    }
    return arr[top--];
}

void stk::display(){
    if (top==-1){
        cout<<"Stack Underflow...";
    }
    for(int i=0;i<top+1;i++){
        cout<<arr[i]<<"   ";
    }
    return;
}

int main(){
    stk s1,s2;
    int num,temp,revno=0,dig=0,ele;
    cout<<"Enter the number: ";
    cin>>num;
    temp=num;
    while (temp>0){
        dig=temp%10;
        s1.push(dig);
        temp/=10;
    }

    while (true){
        ele=s1.pop();
        if (ele==-1){
            break;
        }
        s2.push(ele);
    }

    while (true){
        dig=s2.pop();
        if (dig==-1){
            break;
        }
        revno=(revno*10)+dig;
    }

    if (revno==num){
        cout<<"The number IS a palindrome...";
    }
    else{
        cout<<"The number is NOT a palindrome...";
    }


    /*while(true){
        cout<<"\n\nMENU\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n";
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch){
        case 1:
            s.push();
            break;
        case 2:
            ele=s.pop();
            cout<<ele<<" is the popped element...";
            break;
        case 3:
            s.display();
        case 4:
            exit(0);
        default:
            cout<<"Invalid Operation...";
            exit(0);
        }
    }*/
return 0;
}

