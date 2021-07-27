//https://leetcode.com/problems/score-of-parentheses/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
int scoreOfParentheses(string s)
{
    stack<int> stack;
    int cur = 0;
    for (char i : s)
        if (i == '(')
        {
            stack.push(cur);
            cur = 0;
        }
        else
        {
            cur += stack.top() + max(cur, 1);
            stack.pop();
        }
    return cur;
}
int main()
{
    string s = "";
    cin >> s;
    int ans = scoreOfParentheses(s);
    cout << "Result is: " << ans << endl;
}