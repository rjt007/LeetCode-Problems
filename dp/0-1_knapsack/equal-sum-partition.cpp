//Equal Sum Partition
//https://leetcode.com/problems/partition-equal-subset-sum/

#include<bits/stdc++.h>
using namespace std;

//Tabulation Code
bool subsetsum(int n, vector<int> v, int sum)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (v[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

bool equalsum(int n, vector<int> v)
{
    int sum = 0;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        sum+=v[i];
    }
    if(sum%2!=0)
    {
        return false;
    }
    else
    {
        ans = subsetsum(n,v,sum/2);
    }
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
    bool ans = equalsum(n, v);
    cout << "Result is: " << ans << endl;
    return 0;
}