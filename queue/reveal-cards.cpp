//https://leetcode.com/problems/reveal-cards-in-increasing-order/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.rbegin(), deck.rend());
    deque<int> d;
    d.push_back(deck[0]);
    for (int i = 1; i < deck.size(); i++)
    {
        d.push_front(d.back());
        d.pop_back();
        d.push_front(deck[i]);
    }
    vector<int> res(d.begin(), d.end());
    return res;
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    vector<int> ans = deckRevealedIncreasing(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}