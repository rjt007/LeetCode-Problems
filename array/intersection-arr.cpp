//https://leetcode.com/problems/intersection-of-two-arrays/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) AND S.C->O(N), set solution.
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s1(begin(nums1), end(nums1));
    unordered_set<int> s2(begin(nums2), end(nums2));
    int n1 = s1.size(), n2 = s2.size();
    vector<int> v;
    if (n1 >= n2)
    {
        for (auto it : s2)
        {
            if (s1.find(it) != s1.end())
            {
                v.push_back(it);
            }
        }
    }
    else
    {
        for (auto it : s1)
        {
            if (s2.find(it) != s2.end())
            {
                v.push_back(it);
            }
        }
    }
    return v;
}
int main()
{
    int n1,n2;
    cout << "Enter size of array1 and array2: ";
    cin >> n1>>n2;
    vector<int> nums1, nums2;
    int val;
    cout << "Enter Array1 :\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        nums1.push_back(val);
    }
    cout << "Enter Array2 :\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        nums2.push_back(val);
    }
    vector<int>ans = intersection(nums1,nums2);
    cout << "Result is: \n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}