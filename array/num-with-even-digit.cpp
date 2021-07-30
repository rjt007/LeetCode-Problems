//https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N^2) & S.C->O(N^2);//to_string();
int findNumbers(vector<int> &nums)
{
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s = to_string(nums[i]);
        int l = s.length();
        if (l % 2 == 0)
        {
            ans++;
        }
    }
    return ans;
}
/*
//T.C->O(N^2) & S.C->O(1);
int findNumbers(vector<int> &nums)
{
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= 9)
        {
            continue;
        }
        int cnt = 0;
        while (nums[i])
        {
            nums[i] = nums[i] / 10;
            cnt++;
        }
        if (cnt % 2 == 0)
        {
            ans++;
        }
    }
    return ans;
}*/
int main()
{
    int n;
    cin >> n;
    vector<int> alt;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        alt.push_back(val);
    }
    int ans = findNumbers(alt);
    cout << "Result is: " << ans << endl;
    return 0;
}