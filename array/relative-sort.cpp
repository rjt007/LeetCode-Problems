//https://leetcode.com/problems/relative-sort-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N^2) & S.C->O(N).
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int cnt = 0;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                swap(arr1[j], arr1[cnt]);
                cnt++;
            }
        }
    }
    sort(arr1.begin() + cnt, arr1.end());
    return arr1;
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
    vector<int>ans = relativeSortArray(nums1,nums2);
    cout << "Result is: \n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}