//https://leetcode.com/problems/ransom-note/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N).
bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> m1, m2;
    int n1 = ransomNote.size(), n2 = magazine.size();
    bool ans = true;
    for (int i = 0; i < n1; i++)
    {
        m1[ransomNote[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        m2[magazine[i]]++;
    }
    for (auto x : m1)
    {
        if (m2.find(x.first) == m2.end())
        {
            ans = false;
            break;
        }
        else
        {
            if (x.second > m2.find(x.first)->second)
            {
                ans = false;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    string s1 = "", s2 = "";
    cin>>s1>>s2;
    bool ans = canConstruct(s1,s2);
    cout<<"Result is: "<<ans;
}