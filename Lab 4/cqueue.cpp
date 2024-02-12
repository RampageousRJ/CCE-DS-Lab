#include <iostream>
#define MAX 5
using namespace std;

class cque{
    int q[MAX];
    int f,r;
public:
    cque(){
        f=-1;
        r=-1;
    }
    void enq(int ele);
    void deq();
    void disp();
};

void cque::enq(int ele){
    if ((f==0 && r==MAX-1)||(r==f-1)){
        cout<<"Queue Full";
        return;
    }
    r=(r+1)%MAX;
    q[r]=ele;
    if (f==-1){
        f=0;
    }
}
void cque::deq(){
    if (f==r){
        cout<<"Queue Empty";
        return;
    }
    cout<<"The element removed is: "<<q[f]<<endl;
    f=(f+1)%MAX;
}
void cque::disp(){
    int i;
    for (i=f;i!=r;i=(i+1)%MAX){
        cout<<q[i]<<endl;
    }
    cout<<q[i]<<endl;
}

int main(){
    cque c;
    while(true){
        cout<<"\n\nMENU\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice:";
        int ch,ele;
        cin>>ch;
        if (ch==1){
            cout<<"Enter element: ";
            cin>>ele;
            c.enq(ele);
        }
        else if(ch==2){
            c.deq();
        }
        else if(ch==3){
            c.disp();
        }
        else{
            break;
        }
    }
return 0;
}
