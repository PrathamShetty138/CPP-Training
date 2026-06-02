#include<iostream>
using namespace std;
int main()
{
    int num=123456;
    int sum=0;
    while(num>0)
    {
        int digit=num%10;
        sum+=digit;
        num/=10;
    }
    cout<<sum;
    return 0;
}