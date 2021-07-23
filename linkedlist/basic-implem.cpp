#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
}*head=NULL;
void creation()
{
    node* newnode = new node;
    int val;
    cin>>val;
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=newnode;
}
void insertionatfirst(int val)
{
    node* newnode = new node;
    newnode->data=val;
    newnode->next = head;
    head = newnode;
}
void insertionatend(int val)
{
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    node* newnode = new node;
    newnode->data = val;
    newnode->next=NULL;
    temp->next = newnode;
}
void insertioninbtw(int val, int idx)
{
    node* temp = head;
    int i=0;
    while (i<idx-1)
    {
        temp = temp->next;
        i++;
    }
    node* newnode = new node;
    newnode->data = val;
    newnode->next = temp->next;
    temp->next = newnode;
}
void deletionatfirst()
{
    node* temp = head;
    head = head->next;
    free(temp);
}
void deletionatend()
{
    node* temp = head;
    node* temp1 = head->next;
    while (temp1->next!=NULL)
    {
        temp = temp->next;
        temp1 = temp1->next;
    }
    temp->next=NULL;
    free(temp1);
}
void deletioninbtw(int n)
{
    node* temp=head; 
    node* temp1=head->next;
    int i=0;
    while (i<n-1)
    {
        temp=temp->next;
        temp1=temp1->next;
        i++;
    }
    temp->next = temp1->next;
    free(temp1);
}
bool search(int val)
{
    node* temp = head;
    while (temp!=NULL)
    {
        if(temp->data==val)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void reverse()
{
    node* temp=head;
    node* temp1=head->next;
    node* temp2 = head->next;
    while (temp1!=NULL)
    {
        temp1 = temp1->next;
        temp2->next=temp;
        temp = temp2;
        temp2 = temp1;
    }
    head->next=NULL;
    head = temp;
}
/*
//Recursive method of reversing a linked list.
node* reverserecursive(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* newnode = reverserecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newnode;
}*/
void display()
{
    node* temp = head;
    if(head==NULL)
    {
        return;
    }
    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    int n;
    cout<<"Enter no of nodes in linkedlist: ";
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        cout<<"Enter "<<i<<" element of ll: ";
        creation();
    }
    cout<<endl;
    cout<<"Display ll:\n";
    display();
    cout<<"Reverse of ll is:\n";
    reverse();
    cout<<"Display ll:\n";
    display();
}