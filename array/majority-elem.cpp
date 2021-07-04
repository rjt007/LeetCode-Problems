#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) AND S.C->O(N), using map.
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int maj = INT_MIN;
    int ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    for (auto it : m)
    {
        maj = max(maj, it.second);
        if (maj == it.second)
        {
            ans = it.first;
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
    int ans = majorityElement(nums);
    cout << "Result is: " << ans << endl;
    return 0;
}