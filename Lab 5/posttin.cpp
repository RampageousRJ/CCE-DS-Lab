
#include <iostream>
 #include<string.h>
 using namespace std;

 int const MAX = 100;

 class char_stak{

 char arr[MAX][MAX];
 int top;

public:

// CONSTRUCTOR FUNCTION TO INITIALISE THE CLASS OBJECT
char_stak()
{ top = -1; }

// FUNCTION TO POP AN ELEMENT AND RETURN IT
char* pop(){
if(top == -1)
{
char test[]="error";
cout<<"Underflow Detecteded"<<endl;
return test;
}
return arr[top--];
}

char* peek(){
char test[]="error";

if(top == -1)
return test;
else
return arr[top];
}

// FUNCTION TO PUSH AN ELEMENT
void push(char k[]){
if(top == MAX - 1)
{
cout<<"Overflow Detexted"<<endl;
return;
}
strcpy( arr[++top],k );

}

void display()
{
if(top == -1){
cout<<"Stack is empty"<<endl;
return; }

cout<<endl<<"TOP\n";
for(int i = top; i>=0; i--)
cout<<arr[i]<<"\n";
cout<<"BOTTOM"<<endl;
}
};

int isOperator(char a){
if(a=='+' ||a=='-' ||a=='*' ||a=='/' ||a=='(' ||a==')')
return 1;
return 0;
}

void postfixToInfix(char postfix[]){

 char_stak infix, T;
int i=0;
while(postfix[i] != '\0'){

if( isOperator(postfix[i]) )
{
char *a, *b, str[50] = "(";
b = T.pop();
a = T.pop();

char temp[] = { postfix[i] ,'\0'} ;
strcat(str,a);
strcat(str,temp);
strcat(str,b);
strcat(str,")");
T.push(str);

}

else
{

 char temp[] = { postfix[i] ,'\0'} ;
 T.push(temp);
 }


T.display();
i++;
}
}


int main(){

char postfix[] = "ab+cd/*";
postfixToInfix(postfix);

}
