#include<iostream>
using namespace std;

int main()
{
    int arr[4]={2,7,11,15};
    int target=9;
    int l=0,r=3;
    while(l<r){
        int sum=arr[l]+arr[r];
        if(sum==target){
            cout<<l<<" "<<r<<endl;
            break;
        }
        else if(sum<target){
            l++;
        }
        else{
            r--;
        }
    }
}