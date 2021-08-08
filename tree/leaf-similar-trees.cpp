//https://leetcode.com/problems/leaf-similar-trees/
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
void inorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->val);
    }
    inorder(root->right, v);
}
bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1;
    inorder(root1, v1);
    vector<int> v2;
    inorder(root2, v2);
    if (v1.size() != v2.size())
    {
        return false;
    }
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
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

    bool ans = leafSimilar(root1, root2);
    cout<<"Trees are similar or not? "<<ans<<endl;
    return 0;
}