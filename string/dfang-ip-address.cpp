//https://leetcode.com/problems/defanging-an-ip-address/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
string defangIPaddr(string address)
{
    int n = address.size();
    string s = "";
    for (int i = 0; i < n; i++)
    {
        if (address[i] == '.')
        {
            s.push_back('[');
            s.push_back(address[i]);
            s.push_back(']');
            continue;
        }
        s.push_back(address[i]);
    }
    return s;
}
int main()
{
    string s="";
    cout<<"Enter string: ";
    cin>>s;
    string ans= defangIPaddr(s);
    cout<<"Result is: "<<ans<<endl;
}