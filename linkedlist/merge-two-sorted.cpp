//https://leetcode.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
void creation(ListNode *&head)
{
    ListNode *newnode = new ListNode;
    int val;
    cin >> val;
    newnode->val = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void display(ListNode* head)
{
    ListNode* temp = head;
    if(head==NULL)
    {
        return;
    }
    while (temp!=NULL)
    {
        cout<<temp->val<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
//T.C->O(m+n) & S.C->O(1);
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *dummy = new ListNode;
    dummy->val = -1;
    ListNode *p3 = dummy;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val < p2->val)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}
int main()
{
    ListNode* head1=NULL;
    ListNode* head2=NULL;
    int n;
    cout<<"Enter no of nodes in linkedlist1: ";
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        cout<<"Enter "<<i<<" element of ll1: ";
        creation(head1);
    }
    int m;
    cout<<"Enter no of nodes in linkedlist2: ";
    cin>>m;
    for (int i = 1; i <=m; i++)
    {
        cout<<"Enter "<<i<<" element of ll2: ";
        creation(head2);
    }
    cout<<endl;
    ListNode* ans = mergeTwoLists(head1,head2);
    cout<<"Result is: "<<endl;
    display(ans);
    return 0;
}