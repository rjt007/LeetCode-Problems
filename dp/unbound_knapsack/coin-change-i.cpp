//Coin Change Problem.
//https://www.geeksforgeeks.org/coin-change-dp-7/
#include <bits/stdc++.h>
using namespace std;

int coin_change_1(vector<int> coin,int sum, int n)
{
    int dp[n + 1][sum+ 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if(j==0)
            {
                dp[i][j]=1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int main()
{
    int n;
    cin >> n;
    vector<int> coin;
    int inp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        coin.push_back(inp);
    }
    int sum;
    cin >>sum;
    int ans = coin_change_1(coin, sum, n);
    cout << "Total Number of ways is: " << ans << endl;
    return 0;
}