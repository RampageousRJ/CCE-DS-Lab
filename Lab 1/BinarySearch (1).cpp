#include <iostream>
using namespace std;
int main(){
    int n,key,a[100],first,last,mid,flag=0;
    cout<<"Enter number of terms:";
    cin>>n;
    cout<<"\nEnter the sorted terms:";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\nThe array is:";
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    cout<<"\n\nEnter the key:";
    cin>>key;

    first=0;
    last=n-1;

    do{
       mid=(first+last)/2;

      if (a[mid]==key){
        flag=1;
        break;
      }
      else if (key<a[mid]){
            last=mid-1;
       }
      else{
            first=mid+1;
       }
    } while(first<=last && mid!=key);

    if (flag==1){
        cout<<"\nElement found at position "<<mid+1;
    }
    else{
        cout<<"\nElement not found...";
    }

return 0;
}
