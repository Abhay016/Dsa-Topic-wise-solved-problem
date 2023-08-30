
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

bool check(TreeNode *root, int k, unordered_set<int> &s)
{
    if (root == NULL)
        return false;
    if (check(root->left, k, s))
        return true;
    if (s.count(k - root->val))
        return true;
    s.insert(root->val);
    if (check(root->right, k, s))
        return true;
    return false;
}
bool findTarget(TreeNode *root, int k)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return false;
    unordered_set<int> s;
    return check(root, k, s);
}