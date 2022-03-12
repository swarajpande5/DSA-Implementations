// Program to check wheter the given Binary Tree is Binary Search Tree or not
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int info;
    struct Node *left, *right;
} Node;

Node *newNode(int value)
{
    Node *in = (Node *)malloc(sizeof(Node));
    in->info = value;
    in->left = in->right = NULL;
    return in;
}

Node *create(Node *node, int value)
{
    if (node == NULL)
    {
        node = newNode(value);
        return node;
    }

    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = newNode(value);
            return node;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = newNode(value);
            return node;
        }
    }
    return node;
}

Node *deleteTree(Node *node)
{
    if (node == NULL)
        return NULL;

    deleteTree(node->left);
    deleteTree(node->right);

    free(node);
    return NULL;
}

bool isBSTUtil(Node *node, int minKey, int maxKey)
{
    if (node == NULL)
        return true;

    if (node->info < minKey || node->info > maxKey)
        return false;

    return isBSTUtil(node->left, minKey, node->info) &&
           isBSTUtil(node->right, node->info, maxKey);
}

bool isBST(Node *node)
{
    return isBSTUtil(node, INT_MIN, INT_MAX);
}

// Leetcode: https://leetcode.com/problems/validate-binary-search-tree/
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBSTUtility(TreeNode *node, long long minKey, long long maxKey)
    {
        if (node == NULL)
            return true;

        if (node->val <= minKey || node->val >= maxKey)
            return false;

        return isValidBSTUtility(node->left, minKey, node->val) &&
               isValidBSTUtility(node->right, node->val, maxKey);
    }

    bool isValidBST(TreeNode *root)
    {
        return isValidBSTUtility(root, LLONG_MIN, LLONG_MAX);
    }
};

int main()
{
    Node *root = NULL;

    root = create(root, 15);
    root = create(root, 10);
    root = create(root, 20);
    root = create(root, 8);
    root = create(root, 12);
    root = create(root, 16);
    root = create(root, 25);

    if (isBST(root))
        cout << "This is a BST\n";
    else
        cout << "This is Not a BST\n";

    deleteTree(root);
    return 0;
}
