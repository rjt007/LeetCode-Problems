//https://leetcode.com/problems/increasing-order-search-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};
//T.C->O(N) & S.C->O(N)
void inorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}
TreeNode *increasingBST(TreeNode *root)
{
    vector<int> v;
    inorder(root, v);
    TreeNode *ans = new TreeNode(0);
    TreeNode *curr = ans;
    for (int x : v)
    {
        curr->right = new TreeNode(x);
        curr = curr->right;
    }
    return ans->right;
}