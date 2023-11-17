#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class temp{
    string userName,Email,Password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void Login();
    void SignUP();
    void Forgot();
}obj;

int main(){
    char choice;
    cout<<"\n1- Log-In";
    cout<<"\n2- Sign-Up";
    cout<<"\n3- Forgot Password";
    cout<<"\n4- Exit";
    cout<<"\nEnter Your Choice :: ";
    cin>>choice;
    

    switch(choice){
        case '1':
            cin.ignore();
            obj.Login();
        break;
        case '2':
            cin.ignore();
            obj.SignUP();
        break;
        case '3':
            cin.ignore();
            obj.Forgot();
        break;
        case '4':
            return 0;
        break;
        defualt:
            cout<<"Invalid Selection...!";
    }
}
void temp :: SignUP(){
    cout<<"\nEnter Your User Name :: ";
    getline(cin,userName);
    cout<<"Enter Your Email Address :: ";
    getline(cin,Email);
    cout<<"Enter Your Password :: ";
    getline(cin,Password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}
void temp :: Login(){
 
    cout<<"----------LOGIN---------"<<endl;
    cout<<"Enter Your User Name :: "<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password :: "<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof()){
        if(userName == searchName){
            if(Password == searchPass){
                cout<<"\nAccount Login Succesfull...!";
                cout<<"\nUsername :: "<<userName<<endl;
                cout<<"\nEmail :: "<<Email<<endl;
            }else{
                cout<<"Password is Incorrect...!";
            }
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    }
    file.close();
}
void temp :: Forgot(){
    cout<<"\nEnter Your UserName :: ";
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address :: ";
    getline(cin,searchEmail);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof()){
        if(userName == searchName){
            if(Email == searchEmail){
                cout<<"\nAccount Found...!"<<endl;
                cout<<"Your Password :: "<<Password<<endl;
            }else{
                cout<<"Not found...!\n";
            }
        }else{
            cout<<"\nNot found...!\n";
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    }
    file.close();
}