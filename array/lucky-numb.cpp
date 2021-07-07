//https://leetcode.com/problems/find-lucky-integer-in-an-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N).
int findLucky(vector<int> &arr)
{
    int n = arr.size();
    int mx = -1;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto x : m)
    {
        if (x.first == x.second)
        {
            mx = max(mx, x.first);
        }
    }
    return mx;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        nums.push_back(val);
    }
    int ans = findLucky(nums);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}