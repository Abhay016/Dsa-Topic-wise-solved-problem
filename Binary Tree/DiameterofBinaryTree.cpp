
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int left = solve(root->left, res);
    int right = solve(root->right, res);
    res = max(res, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int res = 0;
    solve(root, res);
    return res;
}