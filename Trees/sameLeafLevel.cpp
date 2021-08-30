// Check if all leaves are at same level in a binary tree
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int info;
    struct Node *left, *right;
}Node;

Node *newNode(int value)
{
    Node *in = (Node *)malloc(sizeof(Node));
    in -> info = value;
    in -> left = in -> right = NULL;
    return in;
}

Node *deleteTree(Node *node)
{
    if(node == NULL)
        return NULL;
    
    deleteTree(node -> left);
    deleteTree(node -> right);

    free(node);
    return NULL;
}

bool checkLeafUtil(Node *root, int level, int *leafLevel)
{
    if(root == NULL)
        return true;
    
    if(root -> left == NULL && root -> right == NULL)
    {
        if(*leafLevel == 0)
        {
            *leafLevel = level;
            return true;
        }

        return (level == *leafLevel);
    }

    return  checkLeafUtil(root -> left, level + 1, leafLevel) &&
            checkLeafUtil(root -> right, level + 1, leafLevel);
}

bool checkLeaf(Node *root)
{
    int level = 0, leafLevel = 0;
    return checkLeafUtil(root, level, &leafLevel);
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // root->right->left->right = newNode(8);

    cout << checkLeaf(root) << "\n";

    deleteTree(root);

    return 0;
}