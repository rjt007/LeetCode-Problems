//Rod Cutting Problem.
//https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
#include <bits/stdc++.h>
using namespace std;

int rod_cutting(vector<int>length, vector<int>price,int n)
{
    int dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> length;
    vector<int> price;
    int inp;
    for (int i = 1; i <=n; i++)
    {
        length.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        price.push_back(inp);
    }
    int ans = rod_cutting(length, price,n);
    cout << "Max profit is: " << ans << endl;
    return 0;
}