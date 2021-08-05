#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
//Bulid tree from Inorder & Preorder.
int search(int inorder[], int start, int end, int key)
{
    for (int i = start; i < end; i++)
    {
        if (inorder[i] == key)
        {
            return i;
        }
    }
    return -1;
}
node *bulidtree(int inorder[], int preorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node *newnode = new node(curr);
    if (start == end)
    {
        return newnode;
    }
    int pos = search(inorder, start, end, curr);
    newnode->left = bulidtree(inorder, preorder, start, pos - 1);
    newnode->right = bulidtree(inorder, preorder, pos + 1, end);
    return newnode;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    int preoder[5] = {1, 2, 4, 5,3};
    int inoder[5] = {4, 2, 5, 1, 3};
    node *root = bulidtree(inoder, preoder, 0, 4);
    cout << "Inorder Is: ";
    inorder(root);
    cout<<endl;
    return 0;
}
