//Joshephus problem--Death in a circle.
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>&v,int idx,int k)
{
    if(v.size()==1)
    {
        cout<<v[0]<<endl;
        return;
    }
    idx = (idx+k)%v.size();
    v.erase(v.begin()+idx);
    solve(v,idx,k);
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>ans;
    for (int i = 1; i <=n; i++)
    {
        ans.push_back(i);
    }
    solve(ans,0,k-1);
    return 0;
}