#include <iostream>
#define MAX 100
using namespace std;

class que{
    int f;
    int r;
    int arr[MAX];
public:
    que(){
    f=-1;
    r=-1;
    }
    void enq(int);
    int deq();
    void display();
};

void que::enq(int ele){
    if (r==MAX-1){
        cout<<"Queue is full...";
    }
    arr[++r]=ele;
}

int que::deq(){
    if (f==r){
        cout<<"Queue is empty...";
        return -999;
    }
    return arr[++f];
}

void que::display(){
    for (int i=f+1;i<=r;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    que q;
    q.enq(13);
    q.enq(5);
    q.enq(2);
    q.enq(16);
    q.enq(90);
    q.enq(1371);
    q.display();
}
