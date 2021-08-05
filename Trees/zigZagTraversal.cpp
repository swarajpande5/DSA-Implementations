// ZigZag Tree Traversal : https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
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

vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;

    if(root == NULL)
        return ans;
    
    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftOrRight = true;

    currLevel.push(root);
    while(!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if(temp)
        {
            ans.push_back(temp -> info);

            if(leftOrRight)
            {
                if(temp -> left)
                    nextLevel.push(temp -> left);
                if(temp -> right)
                    nextLevel.push(temp -> right);
            }

            else 
            {
                if(temp -> right)
                    nextLevel.push(temp -> right);
                if(temp -> left)
                    nextLevel.push(temp -> left);
            }
        }

        if(currLevel.empty())
        {
            leftOrRight = !leftOrRight;
            swap(currLevel, nextLevel);
        }
    }

    return ans;
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);

    vector<int> ans = zigZagTraversal(root);
    for(int x: ans)
        cout << x << " ";
    cout << "\n";

    deleteTree(root);

    return 0;
}