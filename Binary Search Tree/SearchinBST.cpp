
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

TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode *node = root;
    while (node != NULL)
    {
        if (node->val == val)
        {
            return node;
        }
        else if (node->val > val)
        {
            node = node->left;
        }
        else if (node->val < val)
        {
            node = node->right;
        }
    }
    return NULL;
}