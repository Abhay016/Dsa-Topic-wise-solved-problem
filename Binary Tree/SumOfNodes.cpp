
/*   Sum of nodes on the longest path from root to leaf node   */


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void solve(Node *root, int i, int &res, int &level, int sum)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (i > level)
        {
            res = sum + root->data;
            level = i;
        }
        else if (i == level)
        {
            res = max(sum + root->data, res);
        }
        return;
    }
    solve(root->left, i + 1, res, level, sum + root->data);
    solve(root->right, i + 1, res, level, sum + root->data);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int res = 0, level = 0;
    solve(root, 0, res, level, 0);
    return res;
}