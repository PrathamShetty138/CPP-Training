#include<iostream>

using namespace std;
int main()
{
    int nums[5]={12,11,23,4,5};
    int k=3;
    int maxi=0;
    int sum=0;
    int left=0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    maxi=max(sum,max);
    for(int i=k;i<nums.size()-1;i++){
        sum=nums[left]
        maxi=max(sum,maxi);
    }


    return 0;
}