#include<iostream>
#include<string>
using namespace std;

class CGPA_CAL{
private:
int n;
string subjectName[10];
string grade[10];
int gradepoint;
int creditHours[10];

float totalcredit=0;
float totalgradepoint=0;
float cgpa;

float calculateCGPA(){
    
     totalcredit=0;
     totalgradepoint=0;
    for(int i=0;i<n;i++){
        if(grade[i]=="A+"){
            gradepoint=10;
        }
        else if(grade[i]=="A"){
            gradepoint=9;
        }
        else if(grade[i]=="B"){
            gradepoint=8;
        }
        else if(grade[i]=="C"){
            gradepoint=7;
        }
        else if(grade[i]=="D"){
            gradepoint=6;
        }
        else if(grade[i]=="E"){
            gradepoint=5;
        }
        else{
            gradepoint=0;
        }

        totalgradepoint+=gradepoint*creditHours[i];
        totalcredit+=creditHours[i];
        

    }
        cgpa=totalgradepoint/totalcredit;
        return cgpa;

}
public:
void Take_input(){
    cout<<"Enter the Number of subject :";
    cin>>n;
    for(int i=0;i<n;i++){
    cout<<"Enter  the Subject"<<i+1<<":";
    cin>>subjectName[i];
    cout<<"Ennter the Grade :";
    cin>>grade[i];
    cout<<"Enter the Creadit Hours:";
    cin>>creditHours[i];
    }
    cgpa=calculateCGPA();
    
}
void Display_output(){

    cout << "\nNumber of Subjects: " << n << endl;
    cout << "\nSubject\t\tGrade\tCredit Hours\n";

    for(int i=0;i<n;i++){
    cout<<subjectName[i]<<endl;
    cout<<grade[i]<<endl;
    cout<<creditHours[i]<<endl;
    
}
cout<<"Total Credit Hours:"<<totalcredit<<endl;
cout<<"Total Grade point:"<<totalgradepoint<<endl;
cout<<" CGPA :  "<<cgpa<<endl;
}
};
int  main(){
    CGPA_CAL s[3];
    
    for(int i=0;i<2;i++){
        cout<<"Enter details of student:"<<i+1<<endl;
    s[i].Take_input();
    }
    for(int i=0;i<2;i++){
       
        cout<<"------------------------------------"<<endl;
         cout<<"Result"<<endl;
        cout<<"Student"<<i+1<<endl;        
        s[i].Display_output();
    }
    return 0;
}

