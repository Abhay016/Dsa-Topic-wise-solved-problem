
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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inOrder(TreeNode<int> *root, vector<int> &vec)
{
    if (!root)
        return;
    inOrder(root->left, vec);
    vec.push_back(root->data);
    inOrder(root->right, vec);
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> vec;
    inOrder(root, vec);
    TreeNode<int> *rootNode = new TreeNode<int>(vec[0]);
    TreeNode<int> *temp = rootNode;
    int n = vec.size();
    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *rightNode = new TreeNode<int>(vec[i]);
        temp->left = NULL;
        temp->right = rightNode;
        temp = rightNode;
    }
    temp->left = NULL;
    temp->right = NULL;
    return rootNode;
}
