#include <iostream>
using namespace std;

int main(){
    char str[100];
    int count=0;
    cout<<"Enter string: ";
    cin.get(str,100);
    for (int i=0;str[i]!='\0';i++){
        count++;
    }
    cout<<"The length of this string is "<<count;
    return 0;
    }

