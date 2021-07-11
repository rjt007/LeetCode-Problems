//https://leetcode.com/problems/running-sum-of-1d-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C-.O(1)
vector<int> runningSum(vector<int> &nums)
{
    int n = nums.size();
    int currsum = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        currsum += nums[i];
        ans.push_back(currsum);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> v;
    int val;
    cout << "Enter array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    vector<int> ans = runningSum(v);
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}