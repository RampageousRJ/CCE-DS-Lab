#include <iostream>
#define MAX 100
using namespace std;

class stk{
    int top;
    char str[MAX];

public:
    stk(){
    top=-1;
    }
    void push(char);
    char pop();
    void palindrome();
};

void stk::push(char c){
    if (top==MAX-1){
        cout<<"Stack Overflow...";
        return;
    }
    str[++top]=c;
}

char stk::pop(){
    if (top==-1){
        cout<<"Stack Underflow...";
        return '@';
    }
    return str[top--];
}

void stk::palindrome(){
    char str1[MAX];
    cout<<"Enter the string: ";
    cin.get(str1,MAX);
    for(int i=0;str1[i]!='\0';i++){
        push(str1[i]);
    }
    for(int i=0;str1[i]!='\0';i++){
        if (str1[i]!=pop()){
            cout<<"It is NOT a palindrome...";
            return;
        }
    }
    cout<<"It is INDEED a palindrome...";
}

int main(){
    stk object;
    object.palindrome();
return 0;
}
