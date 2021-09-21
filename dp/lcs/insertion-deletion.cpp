//Minimum no of insertion & deletion required to convert string x to y.
//https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/

#include<bits/stdc++.h>
using namespace std;

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
    cin>>x>>y;
    int insertion = y.length() - lcs(x, y, x.length(),y.length());
    int deletion = x.length() - lcs(x, y, x.length(),y.length());
    cout<<"No of insertion & deletion resp. is: "<<insertion<<" "<<deletion<<endl;
    return 0;
}