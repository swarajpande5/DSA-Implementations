// Program to check whether the Binary tree is Perfect or not.
#include<bits/stdc++.h>
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

int depth(Node *node)
{
    int d = 0;
    while(node != NULL)
    {
        d++;
        node = node -> left;
    }
    return d;
}

bool isPerfectUtil(Node *node, int d, int level)
{
    if(node == NULL)
        return true;
    
    if(node -> left == NULL && node -> right == NULL)
        return (d == level+1);
    
    if (node->left == NULL || node->right == NULL)
    return false;

    return  isPerfectUtil(node->left, d, level + 1) &&
            isPerfectUtil(node->right, d, level + 1);
    
}

bool isPerfect(Node *node)
{
    int d = depth(node);
    return isPerfectUtil(node, d, 0);
}

int main()
{
    Node *root = NULL;

    root = create(root, 1);
    root = create(root, 2);
    root = create(root, 3);
    root = create(root, 4);
    root = create(root, 5);
    root = create(root, 6);
    root = create(root, 7);

    if(isPerfect(root))
        printf("Perfect Binary Tree\n");
    else 
        printf("Incomplete Binary Tree\n");
    
    deleteTree(root);
    return 0;
}