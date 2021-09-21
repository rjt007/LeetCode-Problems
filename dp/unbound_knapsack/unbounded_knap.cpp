//Unbounded Knapsack
//https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
#include<bits/stdc++.h>
using namespace std;

int unbounded_knapsack(vector<int>wt, vector<int>val, int W, int n)
{
    int dp[n+1][W+1];
    for (int i = 0; i <n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    for (int i = 1; i <n+1; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cin >> n;
    vector<int> wt;
    vector<int> val;
    int inp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        wt.push_back(inp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        val.push_back(inp);
    }
    int W;
    cin >> W;
    int ans = unbounded_knapsack(wt, val, W, n);
    cout << "Max profit is: " << ans << endl;
    return 0;
}
