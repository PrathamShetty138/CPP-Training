#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string reverseword(string og_str)
{
    stringstream ss(og_str);
    string word;
    string res="";
    while(ss>>word)
    {
        //res=word+" "+res;
        cout<<word<<" ";  
    }
    return res;
}
int main()
{
    //string s="the sky is blue";
    string s="ababababab";
    cout<<reverseword(s);
    return 0;
}
