//Print Shortest Common Supersequece
//https://www.geeksforgeeks.org/print-shortest-common-supersequence/
#include<bits/stdc++.h>
using namespace std;

//Tabulation Code
string print_scs(string x, string y, int n, int m)
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
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    string ans="";
    int i = n, j = m;
    while (i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                ans.push_back(y[j-1]);
                j--;
            }
            else
            {
                ans.push_back(x[i-1]);
                i--;
            }
        }
    }
    while (i>0)
    {
        ans.push_back(x[i-1]);
        i--;
    }
    while (j>0)
    {
        ans.push_back(y[j-1]);
        j--;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string x="";
    string y="";
    cin>>x>>y;

    string ans = print_scs(x,y,x.length(),y.length());
    cout<<"SCS string is: "<<ans<<endl;
    return 0;
}