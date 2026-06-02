#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {11,12,13};
    int ele=12;
    for(int i=0;i<5;i++){
        if(arr[i]==ele){
            arr[i]=-1;
            cout<<"Element found at index "<<i<<endl;
        }

    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    //cout<<*(arr);
    return 0;
}