//Count Subset Sum with given sum.

#include <bits/stdc++.h>
using namespace std;

int countsubsetsum(int n, vector<int> v, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (v[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - v[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int subsetsumwithgivendiff(vector<int>v, int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=v[i];
    }
    int sum1 = (diff+sum)/2;
    int ans = countsubsetsum(n, v,sum1);
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
    int diff;
    cin >> diff;
    int ans = subsetsumwithgivendiff(v,n,diff);
    cout << "Result is: " << ans << endl;
    return 0;
}