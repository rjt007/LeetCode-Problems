//https://leetcode.com/problems/intersection-of-two-linked-lists/
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
int length(ListNode *head)
{
    ListNode *ptr = head;
    int len = 0;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    return len;
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
//T.C->O(N) & S.C->O(1).
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int l1 = length(headA);
    int l2 = length(headB);
    ListNode *p1 = NULL;
    ListNode *p2 = NULL;
    int dif = 0;
    if (l1 > l2)
    {
        dif = l1 - l2;
        p1 = headA;
        p2 = headB;
    }
    else
    {
        dif = l2 - l1;
        p1 = headB;
        p2 = headA;
    }
    while (dif)
    {
        p1 = p1->next;
        if (p1 == NULL)
        {
            return NULL;
        }
        dif--;
    }
    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
        {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
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
    ListNode* ans = getIntersectionNode(head1,head2);
    cout<<"Result is: "<<endl;
    display(ans);
    return 0;
}