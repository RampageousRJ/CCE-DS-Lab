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
    char pop();
};

void stk::push(int ele){
    if (top==MAX-1){
        return;
    }
    arr[++top]=ele;
}

char stk::pop(){
    if (top==-1){
        return '$';
    }
    return arr[top--];
}


int main(){
    stk obj;
    int num,temp,base,conv=0,dig;
    string str="";
    char a,b,c;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"Enter the base: ";
    cin>>base;
    if (base<=1){
        cout<<"Base cannot be less than 2\nEXITING...";
        return 0;
    }
    temp=num;

    while(temp>0){
        dig = temp % base;
        obj.push(dig);
        temp/=base;
    }
    dig=0;
    while (true){
        dig=obj.pop();
        if (dig=='$'){
            break;
        }
        else if(dig<9){
            //strconcat(str,(char)(dig+48))
            str=str+((char)(dig+48));
        }
        else{
            //strconcat(str,(char)(dig+55));
            str=str+((char)(dig+55));
        }
    }
    cout<<str;
return 0;
}
