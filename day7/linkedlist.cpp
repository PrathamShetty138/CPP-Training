#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
   void traverse(Node *head){
        if(!head)return;
        while(head)
        {
            cout<<head->data<<"->";
             head=head->next;
        }
    }
    void addend(Node *head,int a){
         while(head->next!=NULL){
            head=head->next;
         }
         head->next= new Node(a);
    }
    void addbeg(Node *head,int a)
    {
        Node *n=new Node(a);
        if(head!=NULL)
         n->next=head->next;
        head->next = n;
    }
        void addmiddle(Node *head,int val,int pos)
        {
            if(!head) addbeg(head,val);
            Node *n=new Node(val);
            for(int i=1;i<pos&&head->next!=NULL;i++)
            {
                head=head->next;
            }
            n->next=head->next;
            head->next=n;
        }
        void delend(Node *head)
        {
            if(!head)return;
            if(head->next==NULL)
            {
                delete head;
                head=nullptr;
                return;
            }
            while(head->next->next!=NULL)
            {
                head=head->next;
            }
            delete head->next;
            head->next=nullptr;
        }
         void delbeg(Node *head)
         {
             if(!head)return;
             if(head->next==NULL)
             {
                 delete head;
                 head=nullptr;
                 return;
             }
             Node *temp=head->next;
             head->next=temp->next;
             delete temp;
         }
          void delmiddle(Node *head,int pos)
          {
              if(!head)return;
              if(head->next==NULL)
              {
                  delete head;
                  head=nullptr;
                  return;
              }
              for(int i=1;i<pos&&head->next!=NULL;i++)
              {
                  head=head->next;
              }
              if(head->next==NULL)return;
              Node *temp=head->next;
              head->next=temp->next;
              delete temp;
          }

int main()
{
    Node *head; // Sentinel node
    Node *n1=new Node(5);
    head->next=n1;
    Node *n2=new Node(10);
    n1->next=n2;
    Node *n3=new Node(15);
    n2->next=n3;
    Node *n4=new Node(20);
    n3->next=n4;
    traverse(n1);
    cout<<endl;
    addend(head,50);
    traverse(head->next);
    addbeg(head,30);
    cout<<endl;
    traverse(head->next);
    addmiddle(head,25,3);
    cout<<endl;
    traverse(head->next);
    return 0;
}