//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) && S.C->O(1)
bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    string s1 = "", s2 = "";
    bool check = false;
    for (int i = 0; i < word1.size(); i++)
    {
        s1 += word1[i];
    }
    for (int i = 0; i < word2.size(); i++)
    {
        s2 += word2[i];
    }
    if (s1 == s2)
    {
        check = true;
    }
    return check;
}
int main()
{
    string s="", s1="";
    cin>>s>>s1;
    bool ans = arrayStringsAreEqual(s,s1);
    cout<<"Result is: "<<ans<<endl;
}