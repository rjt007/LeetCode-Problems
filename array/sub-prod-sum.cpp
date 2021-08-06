#include<bits/stdc++.h>
using namespace std;
//T.C->O(log(n)) & S.C->O(1)
int subtractProductAndSum(int n)
{
    int sum = 0;
    int product = 1;
    while (n)
    {
        sum += n % 10;
        product *= n % 10;
        n = n / 10;
    }
    return product - sum;
}
int main()
{
    int n;
    cin>>n;
    int ans = subtractProductAndSum(n);
    cout<<"Result is: "<<ans;
}