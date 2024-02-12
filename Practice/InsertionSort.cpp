#include <iostream>
using namespace std;

void insertionSort(int *arr,int n){
    //first loop for number of passes and second loop for shifting values
    for (int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for (;j>=0;j--){
            if(arr[j]>temp){   //basically we compare arr[i-1]>arr[i]
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}

int main(){
    int n,a[100];
    cout<<"Enter number of terms: ";
    cin>>n;
    cout<<"Insert Elements: \n";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    insertionSort(a,n);
    cout<<"\n\nSorted Array: \n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
return 0;
}
