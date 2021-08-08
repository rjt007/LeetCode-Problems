//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
//T.C->O(N) & S.C->O(H)
TreeNode *buildbst(vector<int> v, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(v[mid]);
    root->left = buildbst(v, start, mid - 1);
    root->right = buildbst(v, mid + 1, end);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    TreeNode *root = buildbst(nums, 0, n - 1);
    return root;
}
void inorder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    TreeNode* root = sortedArrayToBST(v);
    inorder(root);
    cout<<endl;
    return 0;
}