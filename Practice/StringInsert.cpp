#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char a[50], b[50];
    cout<<"Enter the main string:"<<endl;
    gets(a);
    cout<<"Enter the sub string:"<<endl;
    gets(b);
    int n, l1, l2;
    cout<<"Enter the location to enter the sub string:";
    cin>>n;
    l1=strlen(a);
    l2=strlen(b);
    for(int i=1;i<=(l1-n);i++){
        a[l1+l2-i]=a[l1-i];
    }
    a[l1+l2]='\0';
    for(int j=0;j<l2;j++){
        a[n+j]=b[j];
    }
    cout<<a;
}
