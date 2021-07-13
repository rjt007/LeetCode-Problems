//https://leetcode.com/problems/determine-if-string-halves-are-alike/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
bool halvesAreAlike(string s)
{
    vector<char> v = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    int n = s.size(), left = 0, right = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (binary_search(v.begin(), v.end(), s[i]))
        {
            left++;
        }
    }
    for (int i = n / 2; i < n; i++)
    {
        if (binary_search(v.begin(), v.end(), s[i]))
        {
            right++;
        }
    }
    return right == left;
}
int main()
{
    string s="";
    cout<<"Enter string: ";
    cin>>s;
    bool ans= halvesAreAlike(s);
    cout<<"Result is: "<<ans<<endl;
}