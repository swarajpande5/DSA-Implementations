// Inorder Predecessor and Successor in BST : https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key;
    struct Node *left, *right;
}Node;

void findPreSuc(Node *root, Node* &pre, Node* &suc, int key)
{
    if(root == NULL)
        return;
    
    // If key is present at root
    if(root -> key == key)
    {
        if(root -> left != NULL)
        {
            Node *temp = root -> left;
            while(temp -> right)
                temp = temp -> right;
            
            pre = temp;
        }

        if(root -> right != NULL)
        {
            Node *temp = root -> right;
            while(temp -> left)
                temp = temp -> left;
            
            suc = temp;
        }
        return;
    }

    // If key is smaller than root's key, traversing left subtree
    if(root -> key > key)
    {
        suc = root;
        findPreSuc(root -> left, pre, suc, key);
    }
    else    // Traversing right subtree
    {
        pre = root;
        findPreSuc(root -> right, pre, suc, key);
    }
}

Node *newNode(int value)
{
    Node *in = (Node *)malloc(sizeof(Node));
    in -> key = value;
    in -> left = in -> right = NULL;
    return in;
}

Node *create(Node *node, int value)
{
    if(node == NULL)
        node = newNode(value);
    
    else if(value <= node -> key)
        node -> left = create(node -> left, value);
    
    else 
        node -> right = create(node -> right, value);

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

int main()
{
    Node *root = NULL;

    root = create(root, 50);
    root = create(root, 30);
    root = create(root, 20);
    root = create(root, 40);
    root = create(root, 70);
    root = create(root, 60);
    root = create(root, 80);

    int key = 65;
    Node *pre = NULL, *suc = NULL;

    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
        cout << "Predecessor is: " << pre->key << endl;
    else
        cout << "No Predecessor";

    if (suc != NULL)
        cout << "Successor is: " << suc->key << endl;
    else
        cout << "No Successor";

    deleteTree(root);
    return 0;

}