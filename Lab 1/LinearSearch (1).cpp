#include <iostream>
using namespace std;

int main(){
    int n,arr[100],key,flag=0,pos;
    cout<<"Enter the number of terms:\n";
    cin>>n;
    cout<<"\nEnter the terms:";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nThe original array is:\n";

    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n\nEnter the key to be found:";
    cin>>key;

    for (int i=0;i<n;i++){
        if (arr[i]==key){
            flag=1;
            pos=i;
            break;
        }
    }

    if (flag==1){
        cout<<"The key was found at position "<<pos+1;
    }
    else{
        cout<<"The key was not found...";
    }

    return 0;
}
