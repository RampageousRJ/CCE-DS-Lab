#include <iostream>
using namespace std;
void InsertS(int arr[],int n)
{
    int i,key,j;
    for (i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void printarr(int arr[],int n)
{
    int i;
    for (i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int n,arr[100];
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"\nEnter the array elements: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    InsertS(arr, n);
    printarr(arr, n);

    return 0;
}
