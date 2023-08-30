
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

int check(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    int left = check(root->left);
    if (left == -1)
        return -1;
    int right = check(root->right);
    if (right == -1)
        return -1;
    if (root->data != (left + right))
        return -1;
    else
        return root->data + left + right;
}
bool isSumTree(Node *root)
{
    if (check(root) == -1)
        return false;
    else
        return true;
}