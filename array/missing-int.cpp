//https://leetcode.com/problems/missing-number/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N), using maths.
int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    int ans = 0, sum_arr = 0;
    for (int i = 0; i < n; i++)
    {
        sum_arr += nums[i];
    }
    ans = sum - sum_arr;
    return ans;
}
/*
//T.C->O(N*LOG(N)) & S.C->O(1)
int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            ans = i;
            break;
        }
    }
    return ans;
}/*
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums;
    int val;
    cout << "Array is:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    int ans = missingNumber(nums);
    cout << "Result is: " << ans << endl;
}