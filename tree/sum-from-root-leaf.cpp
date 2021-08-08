//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left, *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
// T.C->O(N) & S.C->O(H), H is height of tree.
int ans = 0;
void preorder(TreeNode *root, int curr)
{
    if (root == NULL)
    {
        return;
    }
    if (root != NULL)
    {
        curr = (curr << 1) | root->val;
        if (root->left == NULL && root->right == NULL)
        {
            ans += curr;
        }
        preorder(root->left, curr);
        preorder(root->right, curr);
    }
}
int sumRootToLeaf(TreeNode *root)
{
    preorder(root, 0);
    return ans;
}
int main()
{
    /*
    (1)
    / \
   (0) (1)
   / \   / \
  (0)(1)(0) (1)
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    int res = sumRootToLeaf(root);
    cout<<res<<endl;
    return 0;
}