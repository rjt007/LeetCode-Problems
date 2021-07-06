//https://leetcode.com/problems/next-greater-element-i/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) and S.C->O(N)
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    stack<int> s;
    unordered_map<int, int> m; //since each element is unique.
    vector<int> ans(n1, -1);
    for (int i = 0; i < n2; i++)
    {
        int elem = nums2[i];
        while (!s.empty() && elem > s.top())
        {
            m[s.top()] = elem;
            s.pop();
        }
        s.push(elem);
    }
    for (int i = 0; i < n1; i++)
    {
        if (m.find(nums1[i]) != m.end())
        {
            ans[i] = m[nums1[i]];
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums1,nums2;
    int val;
    cout<<"Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        nums1.push_back(val);
    }
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        nums2.push_back(val);
    }
    vector<int>ans = nextGreaterElement(nums1,nums2);
    cout<<"Result is:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}