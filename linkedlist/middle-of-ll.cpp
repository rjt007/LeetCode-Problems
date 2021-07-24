//https://leetcode.com/problems/middle-of-the-linked-list/
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
//T.C->O(N) & S.C->O(1).
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
ListNode *middleNode(ListNode *head)
{
    int l = length(head);
    ListNode *ptr = head;
    int half = l / 2;
    while (half)
    {
        ptr = ptr->next;
        half--;
    }
    return ptr;
}
int main()
{
    ListNode* head=NULL;
    int n;
    cout<<"Enter no of nodes in linkedlist: ";
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        cout<<"Enter "<<i<<" element of ll: ";
        creation(head);
    }
    cout<<endl;
    ListNode* ans = middleNode(head);
    cout<<"Result is: "<<ans->val<<endl;
    return 0;
}