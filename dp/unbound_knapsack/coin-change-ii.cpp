//Coin Change ii - Minimum number of coins req. 
//https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

#include<bits/stdc++.h>
using namespace std;

int coin_change_ii(vector<int>coin, int sum, int n)
{
    int dp[n+1][sum+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j==0)
            {
                dp[i][j]=0;
            }
            if(i==0)
            {
                dp[i][j]=INT_MAX-1;
            }
        }
    }
    //Intializing 2nd row.
    for(int j=1;j<sum+1;j++)
    {
        if(j%coin[0]==0)
        {
            dp[1][j] = j / coin[0];
        }
        else
        {
            dp[1][j] = INT_MAX-1;
        }
    }
    for (int i = 2; i <n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(coin[i-1]<=j)
            {
                dp[i][j] = min(dp[i][j-coin[i-1]]+1,dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        } 
    }
    return dp[n][sum];
}
int main()
{
    int n;
    cin>>n;
    vector<int>coin;
    int inp;
    for (int i = 0; i < n; i++)
    {
        cin>>inp;
        coin.push_back(inp);
    }
    int sum;
    cin>>sum;
    int ans = coin_change_ii(coin,sum,n);
    cout<<"Minimum coins required are: "<<ans<<endl;
    return 0;
}