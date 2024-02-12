#include <iostream>
#define MAX 100
using namespace std;

class stk{
    int top;
    char arr[MAX];
public:
    stk(){
    top=-1;
    }

    void push(char);
    char pop();
    bool IsEmpty();
    void bracketcheck();
};

bool stk::IsEmpty(){
    if (top==MAX-1){
        return true;
    }
    else{
        return false;
    }
}

void stk::push(char c){
    if (IsEmpty()){
        return;
    }
    arr[++top]=c;
}

char stk::pop(){
    if (top==-1){
        return '@';
    }
    return arr[top--];
}

void stk::bracketcheck(){
    cout<<"Enter the expression: ";
    char str[MAX],ele;
    cin.get(str,MAX);
    for(int i=0;str[i]!='\0';i++){
        if (str[i]=='(' || str[i]=='{' || str[i]=='['){
            push(str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            ele=pop();
            if (ele=='@'){
                cout<<"Excess Closures...";
                return;
            }
            else if(ele=='(' && str[i]==')'){}
            else if(ele=='{' && str[i]=='}'){}
            else if(ele=='[' && str[i]==']'){}
            else{
                cout<<"Bracket Mismatch...";
                return;
            }
        }
    }
    if (top!=-1){
        cout<<"Excess Openers...";
    }
    else{
        cout<<"Balanced";
    }
}

int main(){
    stk brack;
    brack.bracketcheck();
return 0;
}
