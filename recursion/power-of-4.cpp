#include <bits/stdc++.h>
using namespace std;
//T.C->O(1) & S.C->O(1), using bit minpulation.
bool isPowerOfFour(int n)
{
    return n > 0 && !(n & (n - 1)) && (n - 1) % 3 == 0;
}
int main()
{
    int n;
    cin>>n;
    bool ans = isPowerOfFour(n);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}