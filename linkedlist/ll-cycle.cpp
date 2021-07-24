//https://leetcode.com/problems/linked-list-cycle/
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
bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    if (fast == NULL)
    {
        return false;
    }
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
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
    bool ans = hasCycle(head);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}
