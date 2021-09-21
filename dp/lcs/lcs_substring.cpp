//Longest Common Substring
//https://www.geeksforgeeks.org/longest-common-substring-dp-29/

#include <bits/stdc++.h>
using namespace std;
//Tabulation Code
int lcs_substring(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if(dp[i][j]>ans)
            {
                ans = dp[i][j];
            }
        }
    }
    return ans;
}
int main()
{
    string x = "";
    string y = "";
    cin >> x >> y;
    int ans = lcs_substring(x, y, x.length(), y.length());
    cout << "Result is: " << ans << endl;
    return 0;
}