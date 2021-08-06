#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1), where n is length of digits.
int maximum69Number(int num)
{
    string s = to_string(num);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '6')
        {
            s[i] = '9';
            break;
        }
    }
    return stoi(s);
}
int main()
{
    int n;
    cin >> n;
    int ans = maximum69Number(n);
    cout << "Result is: " << ans;
}