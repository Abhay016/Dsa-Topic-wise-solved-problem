
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
 
TreeNode *constructTree(vector<int> &postorder, vector<int> &inorder, int n, int &i, int s, int e, unordered_map<int, int> &mp)
{
    if (i < 0 || s > e)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[i]);
    int j = mp[postorder[i]];
    i--;
    root->right = constructTree(postorder, inorder, n, i, j + 1, e, mp);
    root->left = constructTree(postorder, inorder, n, i, s, j - 1, mp);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    int i = n - 1;
    TreeNode *root = constructTree(postorder, inorder, n, i, 0, n - 1, mp);
    return root;
}