//https://leetcode.com/problems/single-number/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) and S.C->O(N), using map.
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> m;
    int n = nums.size();
    int ans;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    for (auto it : m)
    {
        if (it.second == 1)
        {
            ans = it.first;
        }
    }
    return ans;
}
/*
//T.C->O(N) and S.C->O(1), using BIT MANIPULATION
// a xor 0 = a, a xor a = 0, a xor b xor a = b;
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ nums[i];
    }
    return res;
}*/
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
    int ans = singleNumber(nums);
    cout << "Result is: " << ans << endl;
}