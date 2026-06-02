#include<iostream>
using namespace std;
int main()
{
    for(int i=1;i<5;i++)
    {
        for(int sp=0;sp<5-i;sp++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
