#include <iostream>
#define MAX 10
using namespace std;

class spm{
public:
    int r,c,v;
    int read(spm a[]);
    void ftp(spm a[],spm b[]);
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

void spm::ftp(spm a[], spm b[]){

        b[0].r=a[0].c;
        b[0].c=a[0].r;
        b[0].v=a[0].v;

        int rt[20]={0};     //NUMBER OF INDEX REPETITION
        int i,k;
        for(i=1;i<=a[0].v;i++){
            rt[a[i].c]++;
        }

        int sp[30];         //STARTING POSITIONS FOR EACH VALUE
        sp[0]=1;

        for(i=1;i<a[0].c;i++)
            sp[i]=sp[i-1]+rt[i-1];

        for(i=1;i<=a[0].v;i++){
            k=sp[a[i].c]++;
            b[k].r=a[i].c;
            b[k].c=a[i].r;
            b[k].v=a[i].v;

        }
    }

void spm::display(){
    cout<<r<<' '<<c<<' '<<v<<endl;
}

void multiply(spm a[],spm b[],int n1,int m2)
{
    int i;
    for(i=1;i<=a[0].v;i++)
    {
        if(n1==m2)
        {
       b[i].v=a[i].v*b[i].v;
         }
    }
    //  cout<<"not compatible";
}

int main(){

    spm a[MAX],b[MAX],a1;
    cout<<"Enter values: ";
    int cnt=a1.read(a);
    cout<<endl;
    for(int k=0;k<=cnt;k++){
    a[k].display();
    }
    cout<<endl;
    a1.ftp(a,b);
    cout<<endl;
    for(int k=0;k<=cnt;k++){
    b[k].display();
    }
    cout<<endl;
    multiply(a,b,3,3);
    for(int k=0;k<=cnt;k++){
    b[k].display();
    }
return 0;
}
