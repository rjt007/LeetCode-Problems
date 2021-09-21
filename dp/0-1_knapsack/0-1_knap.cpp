//0-1 KnapSack Problem
//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include<bits/stdc++.h>
using namespace std;

/* //Memoization Code(Top-Down)
//Constraints : n<=100 & W<=1000
//dp[n+1][W+1]
int dp[101][1001]; //dp matrix to store values.

int knapsack(vector<int>wt, vector<int>val, int W, int n)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(wt[n-1]<=W)
    {
        return dp[n][W] = max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));
    }
    else if(wt[n-1]>W)
    {
        return dp[n][W] = knapsack(wt, val, W, n - 1);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>wt;
    vector<int>val;
    int inp;
    for (int i = 0; i < n; i++)
    {
        cin>>inp;
        wt.push_back(inp);
    }
    for (int i = 0; i < n; i++)
    {
        cin>>inp;
        val.push_back(inp);
    }
    int W;
    cin>>W;
    memset(dp,-1,sizeof(dp));// Intializing dp matrix with -1.
    int ans = knapsack(wt,val,W,n);
    cout<<"Max profit is: "<<ans<<endl;
    return 0;
}
 */

//Tabulation(Bottom-Up)

int knapsack(vector<int>wt, vector<int>val, int W, int n)
{
    int dp1[n+1][W+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            if(i==0 || j==0)
            {
                dp1[i][j]=0;
            }
        }
    }
    for (int i = 1; i <n+1; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            if(wt[i-1]<=j)
            {
                dp1[i][j] = max(val[i - 1] + dp1[i - 1][j - wt[i - 1]], dp1[i - 1][j]);
            }
            else
            {
                dp1[i][j] = dp1[i-1][j];
            }
        }
    }
    return dp1[n][W];
    
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
    int ans = knapsack(wt, val, W, n);
    cout << "Max profit is: " << ans << endl;
    return 0;
}
