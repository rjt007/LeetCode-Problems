//https : //leetcode.com/problems/maximum-score-from-removing-stones/
#include <bits/stdc++.h>
        using namespace std;
//T.C->O(N) && S.C->O(N)
int maximumScore(int a, int b, int c)
{
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int cnt = 0;
    while (!pq.empty())
    {
        if (pq.top() == 0)
        {
            break;
        }
        int p = pq.top();
        pq.pop();
        int q = pq.top();
        if (p > 0 & q > 0)
        {
            cnt++;
        }
        p--;
        q--;
        pq.pop();
        pq.push(p);
        pq.push(q);
    }
    return cnt;
}
/*
//T.C->O(1) using Maths;
int maximumScore(int a, int b, int c)
{
    int m = max(max(a, b), c);
    if (2 * m > a + b + c)
    {
        return a + b + c - m;
    }
    return (a + b + c) / 2;
}*/
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans = maximumScore(a,b,c);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}