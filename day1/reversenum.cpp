#include<iostream>
using namespace std;
int main()
{
    int num=123456;
    int rev=0;
    int temp=num;
    while(num>0)
    {
        int d=num%10;
        rev=rev*10+d;
        num/=10;
    }
    if(temp==rev)
    {
        cout<<"palindrome";
    }
    else
    {
        cout<<"not palindrome";
    }
    return 0;
}