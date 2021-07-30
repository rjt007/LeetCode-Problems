//https://leetcode.com/problems/sum-of-unique-elements/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N);
int sumOfUnique(vector<int> &nums)
{
    unordered_map<int, int> m;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for (auto x : m)
    {
        if (x.second == 1)
        {
            sum += x.first;
        }
    }
    return sum;
}
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
    int ans = sumOfUnique(alt);
    cout << "Result is: " << ans << endl;
    return 0;
}