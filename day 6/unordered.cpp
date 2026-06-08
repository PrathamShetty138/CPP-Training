#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,string> m;
    m.insert({0,"apple"});
    m.insert({1,"mango"});
    m.insert({2,"banana"});
    m.erase(0);
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}