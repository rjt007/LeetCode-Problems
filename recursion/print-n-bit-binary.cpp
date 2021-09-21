//Print all binary digits having more 1 than 0 in prefix.
#include<bits/stdc++.h>
using namespace std;

void solve(int zero,int one,int n,string op,vector<string>&v)
{
    if(n==0)
    {
        v.push_back(op);
        return;
    }
    
    string op1 = op;
    op1.push_back('1');
    solve(zero, one + 1, n - 1, op1, v);

    if(zero<one)
    {
        string op2 = op;
        op2.push_back('0');
        solve(zero+1,one,n-1,op2,v);
    }
    return;
}

vector<string>printallbinary(int n)
{
    vector<string>s;
    int zero=0;
    int one=0;
    string out = "";
    solve(zero,one,n,out,s);
    return s;
}
int main()
{
    int n;
    cin>>n;
    vector<string>ans = printallbinary(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}