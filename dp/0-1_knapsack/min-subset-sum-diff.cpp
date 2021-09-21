//Minimum Subset Sum Difference
//https://bit.ly/3Egpwtf

#include<bits/stdc++.h>
using namespace std;

vector<int>subsetsum(vector<int>v,int n,int sum)
{
    bool dp[n+1][sum+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0)
            {
                dp[i][j] = false;
            }
            if(j==0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(v[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int>lastrow;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if(i==n && j<=sum/2)
            {
                if(dp[i][j]==true)
                {
                    lastrow.push_back(j);
                }
            }
        }
    }
    return lastrow;
}
int minsubsetdiff(vector<int>v,int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=v[i];
    }
    vector<int>lastrow = subsetsum(v,n,sum);
/*     for (int i = 0; i< lastrow.size(); i++)
    {
        cout<<lastrow[i]<<" ";
    } */
    return sum-2*lastrow[lastrow.size()-1];
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    int ans = minsubsetdiff(v,n);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}