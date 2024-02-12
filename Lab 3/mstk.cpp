//Program to implement N stacks in a single array
#include <iostream>
#define MAX 100
using namespace std;

const int N=5;
class mstk{
    private:
    int arr[MAX]={0};
    int top[N];
    int boundary[N+1];
    public:
    mstk(){
        for(int i=0,j=-999;i<N;i++,j+=MAX/N){
            top[i]=j;
            boundary[i]=j;
        }
        boundary[N]=MAX-999;
    }
    bool isEmpty(int stk){
        if(top[stk]==boundary[stk]){
            return true;
        }
        return false;
    }

    bool isFull(int stk){
        if(top[stk]+1==boundary[stk+1]){
            return true;
        }
        return false;
    }

    int push(int elem, int stk){
        if(!(isFull(stk))){
            arr[++top[stk]]=elem;
            return 1;
        }
        return -999;
    }

    int pop(int stk){
        if(!isEmpty(stk)){
            return arr[top[stk]--];
        }
        return -999;
    }

    int peek(int stk){
        if(!isEmpty(stk)){
            return arr[top[stk]];
        }
        return -999;
    }

};

int main(){
    mstk S;
    S.push(1,0);
    S.push(2,0);
    S.push(2,1);
    S.push(3,2);
    S.push(4,3);
    S.push(5,4);
    cout<<S.peek(0)<<endl;
    cout<<S.peek(1)<<endl;
    cout<<S.peek(2)<<endl;
    cout<<S.peek(3)<<endl;
    cout<<S.peek(4)<<endl;
}
