#include <iostream>
#define MAX 100
using namespace std;

class evalpost {
    private:
    int top;
    int arr[MAX];
    public:
    evalpost(){
        top=-1;
    }
    int cal(int,int,char);
    void eval(char pfix[]);
    void push(int ele){
        if (top==MAX-1){
            return;
        }
        arr[++top]=ele;
    }

    int pop(){
        if (top==-1){
            cout<<"Stack underflow";
            return -1;
        }
        return arr[top--];
    }

};

int evalpost::cal(int a,int b,char op){
    switch (op){
case '+':return a+b;
case '-':return a-b;
case '*':return a*b;
case '/':return a/b;
    }
}

void evalpost::eval(char pfix[]){
    int op1,op2,res;
    for(int i=0;pfix[i]!='\0';i++){
        if(pfix[i]=='+'||pfix[i]=='-'||pfix[i]=='*'||pfix[i]=='/'){
            op2=pop();
            op1=pop();
            res=cal(op1,op2,pfix[i]);
            push(res);
        }
        else{
            push(pfix[i]-'0');
        }
    }
    cout<<"Final Answer: "<<arr[top];
}

int main(){
    char s[MAX];
    evalpost e;
    cout<<"Enter expression:";
    cin>>s;
    e.eval(s);
}
