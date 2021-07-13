//https://leetcode.com/problems/truncate-sentence/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
string truncateSentence(string s, int k)
{
    int cnt = 0, n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            cnt++;
        }
        if (cnt == k)
        {
            s.erase(i);
            break;
        }
    }
    return s;
}
int main()
{
    string s="";
    cout<<"Enter string: ";
    getline(cin,s);
    int k;
    cin>>k;
    string ans= truncateSentence(s,k);
    cout<<"Result is: "<<ans<<endl;
}