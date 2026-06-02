#include<iostream>
#include<string>
using namespace std;
/*int main()
{
    string s1,s2,s3;
    cout<<"enter your Name,dept,classNo"<<endl;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    cout<<"Name: "<<s1<<endl;
    cout<<"Department: "<<s2<<endl;
    cout<<"Class No: "<<s3<<endl;
    return 0;
}*/
string substr(int st,int end,string og_str)
{
  string result="";
  for(int i=st;i<end;i++)
  {
    result+=og_str[i];
  }
  return result;
}
int main()
{
    string s="computer";
    cout<<substr(1,2,s);
    return 0;
}