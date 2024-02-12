#include <iostream>
using namespace std;

void SelectionSort(int a[],int n){
    int pos,small,temp;
    for (int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            pos=i;
            small=a[i];
            for(int j=i+1;j<n-1;j++){
                if (small>a[j]){
                    pos=j;
                    small=a[j];
                }
            }
            temp=a[pos];
            a[pos]=a[i];
            a[i]=temp;
        }
    }
}

int main(){
    int n,a[100];
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"\nEnter the array elements: \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\nArray formed is: \n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    SelectionSort(a,n);



    cout<<"\nThe new array is:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


return 0;
}

