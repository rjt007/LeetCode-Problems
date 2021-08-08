//https://leetcode.com/problems/invert-binary-tree/
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
void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    preorder(root->left);
    preorder(root->right);
}
TreeNode *invertTree(TreeNode *root)
{
    preorder(root);
    return root;
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    TreeNode* res = invertTree(root);
    cout << res << endl;
    return 0;
}