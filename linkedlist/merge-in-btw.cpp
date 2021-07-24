//https://leetcode.com/problems/merge-in-between-linked-lists/
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
ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *p1 = list1;
    ListNode *p2 = list1;
    ListNode *p3 = list2;
    while (a - 1)
    {
        p1 = p1->next;
        a--;
    }
    while (b + 1)
    {
        p2 = p2->next;
        b--;
    }
    while (p3->next != NULL)
    {
        p3 = p3->next;
    }
    p1->next = list2;
    p3->next = p2;
    return list1;
}
int main()
{
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    int n;
    cout << "Enter no of nodes in linkedlist1: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter " << i << " element of ll1: ";
        creation(head1);
    }
    int m;
    cout << "Enter no of nodes in linkedlist2: ";
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cout << "Enter " << i << " element of ll2: ";
        creation(head2);
    }
    cout << endl;
    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    ListNode *ans = mergeInBetween(head1, a,b,head2);
    cout << "Result is: " << endl;
    display(ans);
    return 0;
}