#include<iostream>
#include<string>
using namespace std;
int sizestr(string og_str)
{
    int count=0;
    for(auto ch:og_str){
        count++;
    }
     return count;
}
int main()
{
    string s="ronak";
    cout<<sizestr(s);
    return 0;
}