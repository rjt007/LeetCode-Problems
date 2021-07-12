#include <bits/stdc++.h>
using namespace std;
//T.C->O(1) & S.C->O(N).
int numJewelsInStones(string jewels, string stones)
{
    unordered_map<char, int> m;
    int n1 = jewels.size();
    int n2 = stones.size();
    int cnt = 0;
    for (int i = 0; i < n2; i++)
    {
        m[stones[i]]++;
    }
    for (int i = 0; i < n1; i++)
    {
        if (m.find(jewels[i]) != m.end())
        {
            cnt += m.find(jewels[i])->second;
        }
    }
    return cnt;
}
int main()
{
    string s="";
    string s1="";
    cout<<"Enter string s & s1: ";
    cin>>s>>s1;
    int ans = numJewelsInStones(s,s1);
    cout<<"Result is: "<<ans<<endl;
}