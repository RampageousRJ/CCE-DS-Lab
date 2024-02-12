#include <iostream>
#define MAX 100
using namespace std;

class stk{
    int top;
    int arr[MAX];
public:
    stk(){
    top=-1;
    }

    void push(int);
    int pop();
    void display();
};

void stk::push(int c){
    if (top==MAX-1){
        return;
    }
    arr[++top]=c;
}

int stk::pop(){
    if (top==-1){
        return -999;
    }
    return arr[top--];
}

void stk::display(){
    for (int i=top;i>=0;i--){
        cout<<arr[i]<<endl;
    }
}

int main(){
    stk s;
    s.push(1);
    s.push(90);
    s.push(7);
    s.push(5);
    s.push(3);
    s.display();
return 0;
}

