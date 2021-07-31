//https://leetcode.com/problems/merge-strings-alternately/
#include<bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
string mergeAlternately(string word1, string word2)
{
    int n1 = word1.size();
    int n2 = word2.size();
    string ans = "";
    int i = 0, j = 0;
    while (i < n1 || j < n2)
    {
        if (i < n1 && j < n2)
        {
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
            continue;
        }
        if (i < n1)
        {
            ans += word1[i];
            i++;
        }
        if (j < n2)
        {
            ans += word2[j];
            j++;
        }
    }
    return ans;
}
int main()
{
    string s1="",s2="";
    cin>>s1>>s2;
    string ans = mergeAlternately(s1,s2);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}