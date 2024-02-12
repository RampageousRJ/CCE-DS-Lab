#include <iostream>
#define MAX 100
using namespace std;

class spm{
    int r;
    int c;
    int v;
public:
    void read(spm a[]);
    int diagsum(spm a[]);
    void display(spm s[]);
    void del(spm a[]);
    void insrt(spm s[]);
};

void spm::read(spm a[]){
    int k=1,m,n,ele;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    a[0].r=m;
    a[0].c=n;
    cout<<"Matrix Elements:\n";
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>ele;
            if (ele==0){
                continue;
            }
            a[k].r=i;
            a[k].c=j;
            a[k++].v=ele;
        }
    }
    a[0].v=k-1;
}

int spm::diagsum(spm a[]){
    int sum=0;
    for (int i=1;i<=a[0].v;i++){
        if (a[i].r==a[i].c){
            sum+=a[i].v;
        }
    }
    return sum;
}

void spm::display(spm s[]){
    for (int k=0;k<=s[0].v;k++){
        cout<<s[k].r<<' '<<s[k].c<<' '<<s[k].v<<endl;
    }
    cout<<endl;
}

void spm::del(spm a[]){
    cout<<"Enter element to be deleted: ";
    int ele,flag=0;
    cin>>ele;
    for (int i=1;i<=a[0].v;i++){
        if (ele==a[i].v){
            flag=1;
            for(int j=i;j<=a[0].v;j++){
                a[j]=a[j+1];
            }
            a[0].v--;
        }
    }

    if (flag==0){
        cout<<"Element not found...\n\n";
        return;
    }
}

void spm::insrt(spm a[]){
    int ele,row,col,pos;
    cout<<"Enter element, row and column: ";
    cin>>ele>>row>>col;
    for (int i=1;i<=a[0].v;i++){
        if (row>a[i].r){
            continue;
        }
        else if(row==a[i].r){
            if (col>a[i].c){
                continue;
            }
            pos = i;
            for (int j=a[0].v;j>pos-1;j--){
                a[j+1]=a[j];
            }
            a[pos].r=row;
            a[pos].c=col;
            a[pos].v=ele;
        }
    }
    a[0].v++;
}

int main(){
    spm s[MAX],s1;
    s1.read(s);
    s1.display(s);
    //int sum=s1.diagsum(s);
    //cout<<"Sum of diagnol elements is: "<<sum;
   // s1.del(s);
    s1.insrt(s);
    s1.display(s);
    return 0;
}
