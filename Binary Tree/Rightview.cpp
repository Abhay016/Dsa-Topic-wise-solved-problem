
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

void solve(TreeNode *root, int i, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (i == res.size())
    {
        res.push_back(root->val);
    }
    solve(root->right, i + 1, res);
    solve(root->left, i + 1, res);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    solve(root, 0, res);
    return res;
}