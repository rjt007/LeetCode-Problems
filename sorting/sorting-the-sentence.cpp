//https://leetcode.com/problems/sorting-the-sentence/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N), S.C->O(N)
string sortSentence(string s)
{
    vector<string> v;
    string val = "", ans = "";
    int last = 0;
    for (int i = 0; i < s.length(); i++)
    {
        val += s[i];
        if (s[i] == ' ')
        {
            last = i;
            val.pop_back();
            v.push_back(val);
            val.clear();
        }
    }
    v.push_back(s.substr(last + 1));
    if (last == 0)
    {
        ans = s.substr(0, s.size() - 1);
        return ans;
    }
    vector<string> v1(v.size(), "00");
    for (int i = 0; i < v.size(); i++)
    {
        string str = v[i];
        char l = v[i].back();
        int idx = (l - '0') - 1;
        v1[idx] = v[i].substr(0, v[i].size() - 1);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        ans += v1[i] + " ";
    }
    ans.pop_back();
    return ans;
}
int main()
{
    string s = "";
    getline(cin,s);
    string ans = sortSentence(s);
    cout<<ans<<endl;
    return 0;
}