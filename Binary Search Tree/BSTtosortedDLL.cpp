
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(TreeNode<int> *root, TreeNode<int> *&prev, TreeNode<int> *&head)
{
    if (root == NULL)
    {
        return;
    }
    solve(root->left, prev, head);
    if (prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    solve(root->right, prev, head);
}
TreeNode<int> *bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int> *prev = NULL;
    TreeNode<int> *head = NULL;
    solve(root, prev, head);
    return head;
}