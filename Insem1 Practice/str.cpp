#include <iostream>
#define MAX 100;
#include <string.h>
using namespace std;

class dchar{
    char str[50];
    char key;
    public:
        void getstr(){
            cout<<"Enter the string:";
            cin>>str;
            cout<<"Enter the character to be deleted:";
            cin>>key;
        }
        void deletechar(){
            int i,j;
            for(i=0;i<strlen(str);i++){
                if(str[i]==key){
                    for(j=i;j<strlen(str);j++)
                    str[j]=str[j+1];
                }
                str[j]='\0';
            }
                cout<<str;
        }
};
int main(){
    dchar d;
    d.getstr();
    d.deletechar();
return 0;
}
