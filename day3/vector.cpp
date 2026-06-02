#include<iostream>
using namespace std;
  
/*template<typename T>
T sum(T a, T b){
    return a + b;
}*/
template<typename T,typename K>
T sum(T a, K b){
    return a + b;
}

int main(){
    cout<<sum(3,4.5)<<endl;
    return 0;
}
class Vector{
    
};
 