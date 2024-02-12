#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

class stk{
    int top;
    char arr[][MAX];
    public:
    stk(){
        top=-1;
    }
    void push(char str[]){
        if(top==MAX-1){
            cout<<"Stack full";
            return;
        }
        strcpy(arr[++top],str);
    }
};