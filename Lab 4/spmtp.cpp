
#include <iostream>
#define MAX 10
using namespace std;

class spm{
public:
    int r,c,v;
    int read(spm a[]);
    void transpose(spm a[],spm b[]);
    void display();
};

int spm::read(spm a[]){
    int k=1,m,n,ele,cnt=0;
    cout<<"Enter number of columns and rows: ";
    cin>>m>>n;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>ele;
            if (ele==0){
                continue;
            }
            a[k].r=i;
            a[k].c=j;
            a[k++].v=ele;
            cnt++;
        }
    }
    a[0].r=m;
    a[0].c=n;
    a[0].v=k-1;
    return cnt;
}

void spm::transpose(spm a[],spm b[]){
    int k=1;
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    for(int i=0;i<a[0].c;i++){
        for (int j=1;j<=a[0].v;j++){
            if (i==a[j].c){
                b[k].c=a[j].r;
                b[k].r=a[j].c;
                b[k].v=a[j].v;
                k++;
            }
        }
    }
}

void spm::display(){
    cout<<r<<' '<<c<<' '<<v<<endl;
}

int main(){

    spm a[MAX],b[MAX],a1;
    int cnt=a1.read(a);
    cout<<endl;
    for(int k=0;k<=cnt;k++){
    a[k].display();
    }
    cout<<endl;
    a1.transpose(a,b);
    cout<<endl;
    for(int k=0;k<=cnt;k++){
    b[k].display();
    }
return 0;
}
