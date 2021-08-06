#include <bits/stdc++.h>
using namespace std;
//T.C->O(log(n)) & S.C->O(1)
int numberOfSteps(int num)
{
    int ans = 0;
    while (num)
    {
        if (num % 2 == 1)
        {
            num--;
        }
        else
        {
            num /= 2;
        }
        ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int ans = numberOfSteps(n);
    cout << "Result is: " << ans;
}