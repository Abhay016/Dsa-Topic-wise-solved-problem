
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

int solve(TreeNode *node)
{
    if (node == NULL)
        return -1;
    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    int left = solve(node->left);
    int right = solve(node->right);
    return 1 + max(left, right);
}

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return solve(root);
}