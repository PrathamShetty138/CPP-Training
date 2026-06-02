#include<iostream>
using namespace std;
int main()
{
    int ch,id;
    string username,password;
    while(1)
    {
    cout<<"1.Register"<<endl;
    cout<<"2.Login"<<endl;
    cout<<"3.Admin login"<<endl;
    cout<<"4.Logout"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>ch;
        switch(ch)
        {
              case 1:cout<<"enter userid"<<endl;
                     cin>>id;
                     cout<<"enter username"<<endl;
                     cin>>username;
                     cout<<"enter password"<<endl;
                     cin>>password;
                     cout<<"registered successfully"<<endl;
                     break;
              case 2:cout<<"enter userid"<<endl;
                     cin>>id;
                     cout<<"enter password"<<endl;
                     cin>>password; 
                    cout<<"logged in successfully"<<endl;
                    break;
              case 3:cout<<"enter admin id"<<endl;
                     cin>>id;
                     cout<<"enter password"<<endl;
                     cin>>password;
                     cout<<"admin logged in successfully"<<endl;
                    break;
              case 4:cout<<"logged out successfully"<<endl;
                     break;
              case 5:exit(0);

              default:cout<<"invalid choice"<<endl;

        }        
        
    }
    }