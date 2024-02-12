#include <iostream>
using namespace std;
class stud{
    char name[100];
    int rollno;
    char grade;
    public:
    void Insert(stud s[], int n){
        for (int i=0;i<n;i++){
            cout<<"Enter Name of Student "<<i+1<<": ";
            cin>>s[i].name;
            cout<<"Enter RollNo of Student "<<i+1<<": ";
            cin>>s[i].rollno;
            cout<<"Enter Grade of Student "<<i+1<<": ";
            cin>>s[i].grade;
            cout<<endl;
        }
    }

    void Display(stud s[],int n){
        for (int i=0;i<n;i++){
            cout<<"Name of Student "<<i+1<<": "<<s[i].name<<endl;
            cout<<"RollNo of Student "<<i+1<<": "<<s[i].rollno<<endl;
            cout<<"Grade of Student "<<i+1<<": "<<s[i].grade<<endl;
            cout<<endl;
        }
    }

    void Sort(stud s[],int n){
        stud temp;
        for (int i=0;i<n-1;i++){
            for (int j=0;j<n-i-1;j++){
                if (s[j].rollno > s[j+1].rollno){
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }

        for (int i=0;i<n;i++){
            cout<<"Name: "<<s[i].name<<endl;
            cout<<"RollNo: "<<s[i].rollno<<endl;
            cout<<"Grade: "<<s[i].grade<<endl;
            cout<<endl;
        }
    }
};

int main(){
    stud s[100],s1;
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;
    cout<<endl<<"\nINSERT ELEMENTS\n";
    s1.Insert(s,n);

    cout<<endl<<"\nDISPLAY ELEMENTS\n";
    s1.Display(s,n);
    cout<<endl;

    cout<<endl<<"\nSORT ELEMENTS\n";
    s1.Sort(s,n);


return 0;
}
