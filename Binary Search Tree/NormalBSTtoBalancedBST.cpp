
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inTraversal(TreeNode *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    inTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inTraversal(root->right, inorder);
}
TreeNode *solve(vector<int> inorder, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + (e - s) / 2);
    TreeNode *root = new TreeNode(inorder[mid]);
    root->left = solve(inorder, s, mid - 1);
    root->right = solve(inorder, mid + 1, e);
    return root;
}
TreeNode *balanceBST(TreeNode *root)
{
    vector<int> inorder;
    inTraversal(root, inorder);
    int s = 0, e = inorder.size() - 1;
    return solve(inorder, s, e);
}