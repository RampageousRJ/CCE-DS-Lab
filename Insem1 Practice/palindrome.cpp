#include <iostream>
#define MAX 100
using namespace std;

class pal{
    int top;
    char arr[MAX];
public:
    pal(){
    top=-1;
    }
    void push(char);
    char pop();
    void palindrome();
};

void pal::push(char ele){
    if (top==MAX-1){
        return;
    }
    arr[++top]=ele;
}
char pal::pop(){
    if (top==-1){
        return '@';
    }
    return arr[top--];
}
void pal::palindrome(){
    char str[MAX];
    cout<<"Enter the string: ";
    cin.get(str,MAX);
    for(int i=0;str[i]!='\0';i++){
        push(str[i]);
    }
    for(int i=0;str[i]!='\0';i++){
        if (str[i]!=pop()){
            cout<<"It is NOT a palindrome...";
            return;
        }
    }
    cout<<"It is INDEED a palindrome...";
}

int main(){
    pal p;
    p.palindrome();
return 0;
}
