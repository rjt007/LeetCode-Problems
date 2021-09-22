//Palindrome Partitioning
//https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
#include <bits/stdc++.h>
using namespace std;

/* //Memoization Code
int dp[1001][1001];

bool ispalindrome(string s, int i, int j)
{
    if(i>=j)
    {
        return true;
    }
    while (i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(ispalindrome(s,i,j)==true)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k <= j-1; k++)
    {
        int temp = 1+solve(s,i,k)+solve(s,k+1,j);
        if(ans>temp)
        {
            ans = temp;
        }
    }
    return dp[i][j] = ans;    
} */

//Memoization Code - Optimized Version
int dp[1001][1001];

bool ispalindrome(string s, int i, int j)
{
    if(i>=j)
    {
        return true;
    }
    while (i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(ispalindrome(s,i,j)==true)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k <= j-1; k++)
    {
        int left=0,right=0;
        if(dp[i][k]!=-1)
        {
            left = dp[i][k];
        }
        else
        {
            left = solve(s,i,k);
            dp[i][k] = left;
        }
        if(dp[k+1][j]!=-1)
        {
            right = dp[k+1][j];
        }
        else
        {
            right = solve(s,k+1,j);
            dp[k+1][j] = right;
        }
        int temp = 1+left+right;
        if(ans>temp)
        {
            ans = temp;
        }
    }
    return dp[i][j] = ans;    
}


int main()
{
    string s;
    cin>>s;
    int i=0,j=s.length()-1;
    memset(dp,-1,sizeof(dp));
    int ans = solve(s,i,j);
    cout<<"Minimum Partition Required is: "<<ans<<endl;
    return 0;
}