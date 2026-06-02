#include<bits/stdc++.h>
using namespace std;
class Rectangle{
    public:
          int length;
          int breadth;
          Rectangle(int l,int b)
          {
             length=l;
             breadth=b;
          }
          Rectangle operator+(Rectangle& rhs)
          {
              this->length=this->length+rhs.length;
              this->breadth=this->breadth+rhs.breadth;
              return *this;
          }
};
int main()
{
    Rectangle r1(5,10);
    Rectangle r2(10,20);
    Rectangle  r3=r1+r2;
    cout<<r3.length<<r3.breadth;
    return 0;
}