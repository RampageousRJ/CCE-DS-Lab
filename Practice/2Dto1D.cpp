#include <iostream>
using namespace std;

int main(){
    int a[100][100],n,x[100],y[100],b=0,c=0;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"\nENTER MATRIX ELEMENTS: \n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout<<"\nMATRIX\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i<j){
                x[b++]=a[i][j];
            }
        }
    }

    cout<<"\nUPPER TRIANGULAR ARRAY\n";
    for (int i=0;i<n;i++){
        cout<<x[i]<<"  ";
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i>j){
                y[c++]=a[i][j];
            }
        }
    }

    cout<<"\nLOWER TRIANGULAR ARRAY\n";
    for (int i=0;i<n;i++){
        cout<<y[i]<<"  ";
    }

    return 0;
}
