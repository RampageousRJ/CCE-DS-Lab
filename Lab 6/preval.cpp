#include <iostream>
#include <string.h>
using namespace std;
const int MAX=100;
class Stack {
    private:
    int top;
    char arr[MAX];
    public:
    Stack(){
        top=-1;
    }
    void push(int elem){
        if(top==MAX-1){
            return;
        }
        arr[++top]=elem;
    }
    int pop(){
        if(top==-1){
            return -999;
        }
        return arr[top--];
    }
    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }


int Operator(char ch, int b, int a){
    switch(ch){
        case '*': return(a*b);
        case '+': return(a+b);
        case '-': return(a-b);
        case '/': return(a/b);
        default:
        return 0;
    }
}

int postEval(char post[]){
    int len;
    for (len=0;post[len]!='\0';len++);
    for(int i=0;i<(len/2);i++){
        swap(post[i],post[len-i-1]);
  }
    for(int i=0;post[i]!='\0';i++){
        if(isdigit(post[i])){
            push(post[i]-'0');
        }
        else{
            push(Operator(post[i],pop(),pop()));
        }
    }
    return arr[top];
}
};
int main(){
    Stack s1;
    char s[MAX];
    cout<<"Enter expression: ";
    cin>>s;
    cout<<s1.postEval(s);
    return 0;
}
