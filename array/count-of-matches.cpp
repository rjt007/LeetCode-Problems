#include <bits/stdc++.h>
using namespace std;
//T.C->O(log(n)) & S.C->O(1)
int numberOfMatches(int n)
{
    int ans = 0;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            ans += n / 2;
            n = n / 2;
        }
        else
        {
            ans += (n - 1) / 2;
            n = (n - 1) / 2 + 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int ans = numberOfMatches(n);
    cout << "Result is: " << ans;
}