//https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

//T.C-> O(N*log(N)) and S.C->O(N)
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> v1(nums), v2, v3;
    sort(v1.begin(), v1.end());
    int n = nums.size();
    int start = 0, end = n - 1;
    while (start < end)
    {
        if (v1[start] + v1[end] == target)
        {
            v2.push_back(start);
            v2.push_back(end);
            break;
        }
        else if (v1[start] + v1[end] > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v1[v2[0]] == nums[i] || v1[v2[1]] == nums[i])
        {
            v3.push_back(i);
        }
    }
    return v3;
}

/*
//T.C->O(N) and S.C->O(N)
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> v;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            v.push_back(m[target - nums[i]]);
            v.push_back(i);
            break;
        }
        m[nums[i]] = i;
    }
    return v;
}
*/
int main()
{
    int n;
    cout << "Enter Size of array: ";
    cin >> n;
    vector<int> nums;
    int val;
    cout << "Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    int target;
    cout << "Enter target element: ";
    cin >> target;
    vector<int> ans;
    ans = twoSum(nums, target);
    cout << "Required indices are: ";
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}