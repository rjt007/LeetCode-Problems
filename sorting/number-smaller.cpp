//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N), S.C->O(N)
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> ans;
    vector<int> count(*max_element(nums.begin(), nums.end()) + 1, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(count[nums[i] - 1]);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v,ans;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    ans = smallerNumbersThanCurrent(v);
    cout<<"Result is: \n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}