//https://leetcode.com/problems/intersection-of-two-arrays-ii/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)) AND S.C->O(1).
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> v;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] == nums2[j])
        {
            v.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
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
    vector<int>ans = intersect(nums1,nums2);
    cout << "Result is: \n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}