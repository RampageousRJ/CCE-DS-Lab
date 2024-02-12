#include <iostream>
using namespace std;

void Bubble(int arr[],int n){
    int temp;
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            }
        }
    }

    cout << "\nThe new array in ascending order is:\n";

    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}


int main(){
    int n,arr[100];
    cout << "Enter the number of terms:";
    cin >> n;
    cout << "\nEnter the terms:\n";
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "\nThe original array is:\n";

    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    Bubble(arr,n);

    return 0;
}
