//https://leetcode.com/problems/squares-of-a-sorted-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N), S.C->O(1)
vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (nums[j] * nums[j] >= nums[i] * nums[i])
        {
            ans.push_back(nums[j] * nums[j]);
            j--;
        }
        else
        {
            ans.push_back(nums[i] * nums[i]);
            i++;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    vector<int> ans = sortedSquares(v);
    cout<<"Result is:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}