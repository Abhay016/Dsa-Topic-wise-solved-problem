
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* res=NULL;
        if(root == NULL)
        {
            return res;
        }
        Node* curr= root;
        while(curr != NULL)
        {
            if(curr->data > x->data)
            {
                res = curr;
                curr= curr->left;
            }
            else
            {
                curr= curr->right;
            }
        }
        
        return res;
    }