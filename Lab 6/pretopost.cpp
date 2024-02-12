//Program to convert a Prefix expression to a Postfix expression
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 100
using namespace std;

template <typename T>
class Stack {
    private:
    int top;
    T arr[STACK_SIZE];
    public:
    Stack(){
        top=-1;
    }
    void push(T elem){
        if(top<MAX){
            arr[++top]=elem;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }

    T pop(){
        if(top>=0)
            return arr[top--];
    }

    T peek(){
        if(top>=0)
            return arr[top];
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

string pretoInfix(char pre[]){
    Stack<string> s;
    char output[MAX], fin;
    int l=strlen(pre);
    for(int i=0;i<(l/2);i++){
        swap(pre[i],pre[l-i-1]);
    }
    for(int i=0;i<l;i++){
        if(isdigit(pre[i])||isalpha(pre[i])){
            s.push(string(1,pre[i]));
        }
        else{
            string a=s.pop();
            string b=s.pop();
            string exp='('+b+pre[i]+a+')';
            s.push(exp);
        }
    }
    output=s.peek();
    int len=output.length();
    for(int i=len-1;i>=0;i--){
        if(output[i]=='('){
            fin+=')';}
        else if(output[i]==')'){
            fin+='(';}
        else
        {
            fin+=output[i];
        }
    }
    return fin;
}

int getPriority(char c){
    switch (c)
    {
    case '-':
    case '+':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '$':
    case '^':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

string infixtoPostfix(string infix){
    infix='('+infix+')';
    int l=infix.size();
    string output;
    Stack<char> s;
    for(int i=0;i<l;i++){
        if(isalpha(infix[i])||isdigit(infix[i]))
            output+=infix[i];
        else if(infix[i]=='(')
            s.push(infix[i]);
        else if(infix[i]==')'){
            while(s.peek()!='(')
                output+=s.pop();
            s.pop();
        }
        else{
            while(getPriority(infix[i])<=getPriority(s.peek()))
                output+=s.pop();
            s.push(infix[i]);
        }
    }
    return output;
}

int main(){
    char inp[MAX];
    cout<<"Enter the expression:";
    cin>>inp;
    cout<<infixtoPostfix(pretoInfix(inp));
}
