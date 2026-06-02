#include<iostream>
#include<string>
using namespace std;
int findstr(string og_str,string s)
{
    for(int i=0;i<og_str.size();i++){
        if(og_str[i]==s[0])
        {
            if(og_str[++i]==s[1])
            {
            return i;
            }
        }
    }
    return 0;
}
int main()
{
    string s1="ronakronai";
    string s2="nai";
    cout<<findstr(s1,s2);
    return 0;
}