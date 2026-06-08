#include<iostream>
#include<vector>
using namespace std;
class Queue{
    public:
         vector<int> v;
         int size=0;
         void push(int val)
         {
             v.push_back(val);
             size++;
         }

         void pop(){
            v.erase(v.begin());
            size--;
         }
         void display(){
            for(int i=0;i<size;i++){
                cout<<v[i]<<" ";
            }
         }

};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.size<<endl;
    q.pop();
    cout<<q.size<<endl;
    q.display();
    return 0;
}