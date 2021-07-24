//https://leetcode.com/problems/next-greater-node-in-linked-list/
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
//T.C->O(N) & S.C->O(N)
vector<int> nextLargerNodes(ListNode *head)
{
    vector<int> ans, stack;
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        while (stack.size() && ans[stack.back()] < ptr->val)
        {
            ans[stack.back()] = ptr->val;
            stack.pop_back();
        }
        stack.push_back(ans.size());
        ans.push_back(ptr->val);
        ptr = ptr->next;
    }
    for (auto i : stack)
    {
        ans[i] = 0;
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
    vector<int> ans = nextLargerNodes(head);
    cout<<"Result is:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}