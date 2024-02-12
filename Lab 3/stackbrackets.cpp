#include <iostream>
#define MAX 100
#include <bits/stdc++.h>
using namespace std;

class stk{
    char str[MAX];

public:
    int top;
    stk(){
    top=-1;
    }
    void push(char);
    char pop();
};

void stk::push(char c){
    if (top==MAX-1){
        return;
    }
    str[++top]=c;
}

char stk::pop(){
    if (top==-1){
        return '@';
    }
    return str[top--];
}

int main(){
    stk obj;
    char str1[MAX],c;
    cout<<"Enter the string: ";
    cin.get(str1,MAX);
    for (int i=0;str1[i]!='\0';i++){
        if (str1[i]=='[' || str1[i]=='{' || str1[i]=='(' ){
                obj.push(str1[i]);
            }
        else if(str1[i]==']' || str1[i]=='}' || str1[i]==')' ){
            c=obj.pop();
            if (c=='@'){
                cout<<"EXCESS CLOSURES...";
                return 0;
            }
            else if (c=='[' && str1[i]==']'){
                continue;
            }
            else if (c=='{' && str1[i]=='}'){
                continue;
            }
            else if (c=='(' && str1[i]==')'){
                continue;
            }
            else{
                cout<<"BRACKET MISMATCH ERROR...";
                exit(0);
            }
        }

        else{
            continue;
        }
    }
    if (obj.top!=-1){
        cout<<"EXCESS OPENERS ERROR...";
    }
    else{
        cout<<"BALANCED";
    }

return 0;
}
