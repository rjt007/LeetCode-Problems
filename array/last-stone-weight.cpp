//https://leetcode.com/problems/last-stone-weight/
#include <bits/stdc++.h>
        using namespace std;
//T.C->O(N^2*log(N)) AND S.C->O(1).
int lastStoneWeight(vector<int> &stones)
{
    int n = stones.size();
    sort(stones.begin(), stones.end());
    int store = 0, ans = 0;
    for (int i = n - 1; i > 0; i--)
    {
        store = stones[i] - stones[i - 1];
        stones.pop_back();
        stones.pop_back();
        stones.push_back(store);
        sort(stones.begin(), stones.end());
        n--;
    }
    if (!stones.empty())
    {
        ans = stones[0];
    }
    return ans;
}
/*
//T.C->O(N*log(N)) AND S.C->O(N), using priority queue.
int lastStoneWeight(vector<int> &stones)
{
    int n = stones.size();
    int x = 0, y = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(stones[i]);
    }
    while (pq.size() > 1)
    {
        y = pq.top();
        pq.pop();
        x = pq.top();
        if (y == x)
        {
            pq.pop();
        }
        else
        {
            pq.pop();
            pq.push(y - x);
        }
    }
    int ans = 0;
    if (!pq.empty())
    {
        ans = pq.top();
    }
    return ans;
}
*/
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums;
    int val;
    cout << "Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    int ans = lastStoneWeight(nums);
    cout << "Result is: " << ans << endl;
    return 0;
}