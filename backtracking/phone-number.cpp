//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <bits/stdc++.h>
using namespace std;
vector<string> v = {"00", "11", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans, ans1;
vector<string> phonenumber(string d, string res)
{
    if (d.length() == 0)
    {
        ans.push_back(res);
        return ans;
    }
    char ch = d[0];
    string code = v[ch - '0'];
    string ros = d.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        phonenumber(ros, res + code[i]);
    }
    return ans;
}
vector<string> letterCombinations(string digits)
{
    string res = "";

    if (digits.length() == 0)
    {
        ans1.empty();
        return ans1;
    }
    if (digits.length() == 1)
    {
        char ch = digits[0];
        string code = v[ch - '0'];
        for (int i = 0; i < code.length(); i++)
        {
            string temp = "";
            temp += code[i];
            ans1.push_back(temp);
        }
        return ans1;
    }
    ans1 = phonenumber(digits, res);
    return ans1;
}
int main()
{
    string s = "";
    cin>>s;
    vector<string>ans = letterCombinations(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    cout<<endl;
    return 0;
}