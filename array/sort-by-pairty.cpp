//https://leetcode.com/problems/sort-array-by-parity/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N^2) and S.C->O(N)
vector<int> sortArrayByParity(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] % 2 != 0)
            {
                if (nums[j] % 2 == 0)
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
    return nums;
}
/*
//T.C->O(N) & S.C->O(N)
vector<int> sortArrayByParity(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
        {
            v.push_back(nums[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 != 0)
        {
            v.push_back(nums[i]);
        }
    }
    return v;
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
    vector<int> ans = sortArrayByParity(nums);
    cout << "Result is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
