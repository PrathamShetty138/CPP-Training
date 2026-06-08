#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
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
         Node *n= new Node(a);
         head->next=n;
         n->prev=head;
    }
    void addbeg(Node *head,int a)
    {
        Node *n=new Node(a);
        if(head!=NULL)
         n->next=head->next;
        head->next = n;
        n->prev=head;
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
            if(head->next!=nullptr)
             head->next->prev=n;
            head->next=n;
            n->prev=head;
        }
        void delend(Node *head)
        {
            if(!head)return;

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
             if(temp->next!=nullptr)
              temp->next->prev=head;
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
              Node *temp=head->next;
              head->next=temp->next;
              if(temp->next!=nullptr)
               temp->next->prev=head;
              delete temp; 
          }
int main()
{
    Node *head=new Node(0); // Sentinel node
    Node *n1=new Node(5);
    head->next=n1;
    n1->prev=head;
    Node *n2=new Node(10);
    n1->next=n2;
    n2->prev=n1;
    traverse(head->next);
     addend(head,20);
     cout<<endl;
     traverse(head->next);
        addbeg(head,30);
        cout<<endl;
        traverse(head->next);
        addmiddle(head,25,3);
        cout<<endl;
        traverse(head->next);
        delend(head);
        cout<<endl;
        traverse(head->next);
        delbeg(head);
        cout<<endl;
        traverse(head->next);
        delmiddle(head,2);
        cout<<endl;
        traverse(head->next);
    return 0;
}
