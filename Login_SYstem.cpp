#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class Login_System{
    private:
    string username;
    string passward;

    public:
    void Register(){
        cout<<"Enter the username:"<<endl;
        cin>>username;
        cout<<"Enter the passward:"<<endl;
        cin>>passward;

        if(username.empty() || passward.empty()){
            cout<<"The details can't be empty fill them then you can enter:"<<endl;
            return;
        }

        ifstream file("user.t,lxt");
         string u,p;
        while(file>>u>>p){

            if(u==username || p==passward){
            cout<<"Username and passward already exist"<<endl;
            file.close();
            return ;
        }
    }
    file.close();

    ofstream outfile("user.txt",ios::app);
    outfile<<username<<" "<<passward<<endl;
    outfile.close();

    cout<<"Registration is succesful"<<endl;

}

void Login(){
    string u,p;
    bool found=false;

    cout<<"Enter username"<<endl;
    cin>>u;
    cout<<"Enter passward"<<endl;
    cin>>p;

    ifstream file("user.txt");

    string storedUser, storedPassword;

        while(file>>storedUser>>storedPassword)
        {
            if(storedUser==u && storedPassword==p)
            {
                found=true;
                break;
            }
        }

        file.close();

        if(found)
        {
            cout<<"Login Successful!"<<endl;
        }
        else
        {
            cout<<"Invalid Username or Password!"<<endl;
        }
    }
};


int main()
{
    Login_System l;
    int choice;

    do
    {
        cout<<"\n===================="<<endl;
        cout<<"   LOGIN SYSTEM"<<endl;
        cout<<"===================="<<endl;

        cout<<"1. Register"<<endl;
        cout<<"2. Login"<<endl;
        cout<<"3. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                l.Register();
                break;

            case 2:
                l.Login();
                break;

            case 3:
                cout<<"Goodbye!"<<endl;
                break;

            default:
                cout<<"Invalid Choice!"<<endl;
        }

    }while(choice!=3);
       return 0;
}

