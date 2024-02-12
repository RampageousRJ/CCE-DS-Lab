#include <iostream>
#define MAX 100
#include <string.h>
using namespace std;
class intopost{
    char arr[MAX];
    int top;
public:
    intopost(){
    top=-1;
    }
    void push(char);
    char pop();
    void convexp();
    int prec(char);
};

void intopost::push(char ele){
    if (top==MAX-1){
        return;
    }
    arr[++top]=ele;
}

char intopost::pop(){
    if (top==-1){
        return '@';
    }
    return arr[top--];
}

int intopost::prec(char ele){
    switch(ele){
   case '+':
   case '-':
    return 1;
   case '*':
   case '/':
    return 2;
   default:
    return 0;
    }
}

void intopost::convexp(){
    char str[MAX],conv[MAX],e1;
    int k=0;
    cout<<"Enter expression: ";
    cin.get(str,MAX);
    for (int i=0;str[i]!='\0';i++){
        switch(str[i]){
        case '(':
            push(str[i]);
            break;
        case ')':
            while((e1=pop())!='('){
                    conv[k++]=e1;
                  }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            if (prec(str[i])>prec(arr[top])){
                push(str[i]);
                break;
            }
            else{
                while(prec(str[i])<=prec(arr[top])){
                    conv[k++]=pop();
                }
                push(str[i]);
                break;
            }
        default:
            conv[k++]=str[i];
        }
    }
    while (top!=-1){
        conv[k++]=pop();
    }
    conv[k]='\0';
    cout<<conv;
}

int main(){
    intopost itp;
    itp.convexp();
return 0;
}
