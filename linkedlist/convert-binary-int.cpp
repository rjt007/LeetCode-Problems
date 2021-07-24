//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
void creation(ListNode* &head)
{
    ListNode* newnode = new ListNode;
    int val;
    cin>>val;
    newnode->val=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    ListNode* temp=head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=newnode;
}
//T.C->O(N*LOG(N)) & S.C->O(1)
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
int getDecimalValue(ListNode *head)
{
    int n = length(head);
    ListNode *ptr = head;
    int ans = 0;
    while (ptr != NULL)
    {
        ans += pow(2, n - 1) * ptr->val;
        n--;
        ptr = ptr->next;
    }
    return ans;
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
    int ans = getDecimalValue(head);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}