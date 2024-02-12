#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 100
using namespace std;

class Stk{

private:
    char pfix[MAX], inf[MAX];
    char arr[MAX][MAX];
    int top;

public:
    Stk(){
        top = -1;
    }

    void push(char s[]){
        int i;
        if(top == MAX - 1){
            cout << "Stack overflow" <<endl;
        }
        top++;
        for(i = 0; i < strlen(s); i++){
            arr[top][i] = s[i];
        }
    }
    char* pop(){
        if(top == -1){
            cout << "Stack underflow" <<endl;
        }
        return arr[top--];
    }

    char toConvert(){

        cout << "Enter POSTFIX :"<<endl;
        cin >> pfix;

        int i;
        char sym[2], op1[MAX], op2[MAX], res[MAX];

        for(i = 0; pfix[i] != '\0'; i++){
            sym[0] = pfix[i];
            sym[1] = '\0';
            //cout << sym <<endl;
            if(sym[0] == '+' ||sym[0] == '-' ||sym[0] == '/' ||sym[0] == '*' ){
                strcpy(op1,pop());
                strcpy(op2,pop());
                //cout << op1 << " " << op2 <<endl;
                strcpy(res, "(");
                strcat(res,op1);
                strcat(res,sym);
                strcat(res,op2);
                strcat(res,")");
                //cout << res;
                push(res);
            }
            else{
                push(sym);
            }
        }
        disp();
    }

    void disp(){
        int i;
        for(i = top; i >= 0 ; i--){
            cout << arr[i];
        }
    }

};

int main(){
    Stk s;

    s.toConvert();

    return 0;
}
