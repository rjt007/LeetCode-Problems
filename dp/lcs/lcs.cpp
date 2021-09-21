//Longest Common Subsequence
//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
#include <bits/stdc++.h>
using namespace std;

//Memoization Code
/* 
int dp[1001][1001]; // constraints: n,m<=1000;
int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if (x[n - 1] == y[m - 1])
    {
        return dp[n][m] = 1+ lcs(x, y, n - 1, m - 1);
    }
    else
    {
        return dp[n][m] = max(lcs(x, y, n, m - 1), lcs(x, y, n - 1, m));
    }
    return 0; //redundant
}
int main()
{
    string x = "";
    string y = "";
    cin >> x >> y;
    memset(dp,-1,sizeof(dp));
    int ans = lcs(x, y, x.length(), y.length());
    cout << "Result is: " << ans << endl;
    return 0;
} */

//Tabulation Code
int lcs(string x, string y, int n, int m)
{
    int dp[n+1][m+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string x = "";
    string y = "";
    cin >> x >> y;
    int ans = lcs(x, y, x.length(), y.length());
    cout << "Result is: " << ans << endl;
    return 0;
}