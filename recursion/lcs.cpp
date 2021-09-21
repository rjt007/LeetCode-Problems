//Longest Common Subsequence
//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
#include<bits/stdc++.h>
using namespace std;
int lcs(string x, string y, int n, int m)
{
   if(n==0 || m==0)
   {
       return 0;
   } 
   if(x[n-1]==y[m-1])
   {
       return 1+lcs(x,y,n-1,m-1);
   }
   else
   {
       return max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
   }
   return 0; //redundant
}
int main()
{
    string x = "";
    string y = "";
    cin>>x>>y;
    int ans = lcs(x,y,x.length(),y.length());
    cout<<"Result is: "<<ans<<endl;
    return 0;
}