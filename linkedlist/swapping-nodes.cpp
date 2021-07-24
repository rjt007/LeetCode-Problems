//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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
void display(ListNode *head)
{
    ListNode *temp = head;
    if (head == NULL)
    {
        return;
    }
    while (temp != NULL)
    {
        cout << temp->val << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
//T.C->O(N) & S.C->O(1);
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
ListNode *swapNodes(ListNode *&head, int k)
{
    ListNode *p1 = head;
    ListNode *p2 = head;
    int l = length(head);
    int end = (l - k) + 1;
    while (k - 1)
    {
        p1 = p1->next;
        k--;
    }
    while (end - 1)
    {
        p2 = p2->next;
        end--;
    }
    int temp = p1->val;
    p1->val = p2->val;
    p2->val = temp;
    return head;
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
    int k;
    cout<<"Enter k: ";
    cin>>k;
    ListNode* ans = swapNodes(head,k);
    cout<<"Result is: "<<endl;
    display(head);
    return 0;
}