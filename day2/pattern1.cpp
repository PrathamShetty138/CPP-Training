#include<iostream>
using namespace std;

void printfull(int n)
{
    for(int i=1;i<=n;i++)
    cout<<"*";
}
void printhalf(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(i==1 || i==n)
    {
        cout<<"*";
    }
    else
    {
        cout<<" ";
    }
  }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        if(i==0 || i==n)
        {
            printfull(n);
        }
        else
        {
            printhalf(n);
        }
        cout<<endl;
    }
}