// Merge two binary trees by doing node sum : 
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int info;
    struct Node *left, *right;
}Node;

Node *newNode(int value)
{
    Node *in = new Node;
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

    delete node;
    return NULL;
}

// In Order Traversal
void inOrder(Node *node)
{
    if(node == NULL)
        return;
    
    inOrder(node -> left);
    printf("%d ", node -> info);
    inOrder(node -> right);
}

// Function to merge two trees recursively
Node *mergeTrees(Node *t1, Node *t2)
{
    // If either of the trees is empty
    if(!t1)
        return t2;
    if(!t2)
        return t1;

    t1 -> info += t2 -> info;
    t1 -> left = mergeTrees(t1 -> left, t2 -> left);
    t1 -> right = mergeTrees(t1 -> right, t2 -> right);

    return t1;
}

int main()
{
    /* Let us construct the first Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */
 
    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->right = newNode(6);
 
    /* Let us construct the second Binary Tree
           4
         /   \
        1     7
       /     /  \
      3     2    6   */
    Node *root2 = newNode(4);
    root2->left = newNode(1);
    root2->right = newNode(7);
    root2->left->left = newNode(3);
    root2->right->left = newNode(2);
    root2->right->right = newNode(6);
 
    Node *root3 = mergeTrees(root1, root2);
    
    inOrder(root3);

    deleteTree(root1);
    deleteTree(root2);
    return 0;
}