// Diameter of a binary tree : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
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

Node *create(Node *node, int value)
{
    if(node == NULL)
    {
        node = newNode(value);
        return node;
    }
    
    queue<Node *> q;
    q.push(node);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp -> left != NULL)
            q.push(temp -> left);
        else
        {
            temp -> left = newNode(value);
            return node;
        }

        if(temp -> right != NULL)
            q.push(temp -> right);
        else
        {
            temp -> right = newNode(value);
            return node;
        }
    }
    return node;
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

int diameter(Node *root, int *height)
{
    int leftHeight, rightHeight;
    leftHeight = rightHeight = 0;

    int leftDiameter, rightDiameter;
    leftDiameter = rightDiameter = 0;

    if(root == NULL)
    {
        *height = 0;
        return 0;
    }

    leftDiameter = diameter(root -> left, &leftHeight);
    rightDiameter = diameter(root -> right, &rightHeight);

    *height = 1 + max(leftHeight, rightHeight);

    return max(1 + leftHeight + rightHeight, max(leftDiameter, rightDiameter));
}

int main()
{
    Node *root = NULL;

    root = create(root, 1);
    root = create(root, 2);
    root = create(root, 3);
    root = create(root, 4);
    root = create(root, 5);

    int height = 0;
    cout << diameter(root, &height) << "\n";

    deleteTree(root);
    return 0;
}