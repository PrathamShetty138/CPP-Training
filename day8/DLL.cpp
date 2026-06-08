#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
          int data;
          Node *next;
          Node *prev;
        
        Node(int val){
            data=val;
            next=nullptr;
            prev=nullptr;
        }
};
void traverse(Node *head)
{
    if(!head) return;
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
}
void addend(Node *head,int a)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    Node *n=new Node(a);
    head->next=n;
    n->prev=head;
}

int main()
{
    Node *head;
    Node *n1=new Node(10);
    head->next=n1;
    n1->prev=head;
    Node *n2=new Node(20);
    n1->next=n2;
    n2->prev=n1;
    Node *n3=new Node(30);
    n2->next=n3;
    n3->prev=n2;
    traverse(head->next); 
    addend(head,40);
    cout<<endl; 
    traverse(head->next);
    
    return 0;
}

