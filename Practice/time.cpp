#include<iostream>
using namespace std;

class time{
    int hour;
    int minute;
    int second;
public:
    void update(){
        cout<<"Enter the hour: ";
        cin>>hour;
        cout<<"Enter the minute: ";
        cin>>minute;
        cout<<"Enter the second: ";
        cin>>second;
    }
    void display(){
        cout<<"The time is:- "<<hour<<":"<<minute<<":"<<second<<":"<<endl;
    }
    time add(time t1,time t2){
        int a=t1.hour*3600+t1.minute*60+t1.second;
        int b=t2.hour*3600+t2.minute*60+t2.second;
        int x=(a+b);
        hour=(x/3600);
        minute=((x-hour*3600)/60);
        second=(x-(hour*3600+minute*60));
    }
    time difference(time t1,time t2){
        int a=t1.hour*3600+t1.minute*60+t1.second;
        int b=t2.hour*3600+t2.minute*60+t2.second;
        if(a<b){
            int temp=a;
            a=b;
            b=temp;
        }
        int x=(a-b);
        hour=(x/3600);
        minute=((x-hour*3600)/60);
        second=(x-(hour*3600+minute*60));
    }
};

int main(){
    time t1,t2;
    cout<<"Enter the time "<<endl;
    t1.update();
    t2.update();
    cout<<"The input time is:"<<endl;
    t1.display();
    t2.display();
    time tfinal,tf;
    tfinal.add(t1,t2);
    cout<<"The sum of time taken is: "<<endl;
    tfinal.display();
    tf.difference(t1,t2);
    cout<<"The difference of time taken is: "<<endl;
    tf.display();
    return 0;
}
