//https://leetcode.com/problems/check-if-the-sentence-is-pangram/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(1) && S.C->O(N)
bool checkIfPangram(string sentence)
{
    unordered_map<char, int> m;
    int n = sentence.size();
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        m[sentence[i]]++;
    }
    if (m.size() == 26)
    {
        ans = true;
    }
    return ans;
}
int main()
{
    string s="";
    cin>>s;
    bool ans = checkIfPangram(s);
    cout<<"Result is: "<<ans<<endl;
}