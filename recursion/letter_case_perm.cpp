//Letter case Permutation of a string.
#include <bits/stdc++.h>
using namespace std;

void solve(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<" ";
        return;
    }
    if(isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;
        //op1.push_back(char(ip[0] - 32));
        //op2.push_back(char(ip[0] + 32));
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin() + 0);
        solve(ip, op1);
        solve(ip, op2);
    }
    else
    {
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1);
    }
    return;
}
int main()
{
    string inp;
    cin >> inp;
    string out = "";
    solve(inp, out);
    cout << endl;
    return 0;
}