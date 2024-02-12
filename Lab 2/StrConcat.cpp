#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    char str1[10],str2[10];
    int l1=0,l2=0;
    cout<<"Enter first string: ";
    cin.get(str1,10);
    fflush(stdin);
    cout<<"Enter second string: ";
    cin.get(str2,10);
    for (;str1[l1]!='\0';l1++);
    for (;str2[l2]!='\0';l2++);
    if (l1+l2<10){
        for (int j=0; str2[j]!='\0';j++)
            str1[l1+j]=str2[j];
        cout<<"\nAfter concatenation: "<<str1;
    }
    else
        cout<<"Combined length out of scope...";
    return 0;
}

