//https://leetcode.com/problems/merge-two-binary-trees/
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
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL)
    {
        return root2;
    }
    if (root2 == NULL)
    {
        return root1;
    }
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}
//PREORDER TRAVERSAL
void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    //tree1
    /*                                                    
    (10)
    / \
   (8) (15)
   / 
  (6)*/
  //tree2
    /*
    (5)
    / \
   (10) (25)
   / 
  (45)*/
    TreeNode *root1 = new TreeNode(10);
    root1->left = new TreeNode(8);
    root1->right = new TreeNode(15);
    root1->left->left = new TreeNode(6);

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(10);
    root2->right = new TreeNode(25);
    root2->left->left = new TreeNode(45);

    TreeNode* ans = mergeTrees(root1,root2);
    preorder(ans);
}