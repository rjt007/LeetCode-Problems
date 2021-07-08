//https://leetcode.com/problems/top-k-frequent-elements/
#include<bits/stdc++.h>
using namespace std;
//T.C->O(N) and S.C->O(N)
vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    map<int, int> m;
    multimap<int, int> m2;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    for (auto x : m)
    {
        m2.insert({x.second, x.first});
    }
    for (auto it = m2.rbegin(); it != m2.rend(); it++)
    {
        ans.push_back(it->second);
        cnt++;
        if (cnt == k)
        {
            break;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums;
    int val;
    cout<<"Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        nums.push_back(val);
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;
    vector<int>ans = topKFrequent(nums,k);
    cout<<"Result is:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}