#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1)
int xorOperation(int n, int start)
{
    int ans = start;
    for (int i = 1; i < n; i++)
    {
        ans ^= start + 2 * i;
    }
    return ans;
}
int main()
{
    int n,start;
    cin >> n>>start;
    int ans = xorOperation(n,start);
    cout << "Result is: " << ans;
}