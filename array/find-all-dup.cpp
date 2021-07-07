//https://leetcode.com/problems/find-all-duplicates-in-an-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    for (auto x : m)
    {
        if (x.second == 2)
        {
            ans.push_back(x.first);
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums;
    int val;
    cout << "Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    vector<int> ans = findDuplicates(nums);
    cout << "Result is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}