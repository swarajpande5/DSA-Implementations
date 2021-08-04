// Left View of a Binary Tree : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
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

vector<int> leftView(Node *root)
{
    if(root == NULL)
        return {};
    
    vector<int> ans;
    queue<Node *> q;
    
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        int temp;
        
        while(size--)
        {
            Node *tp = q.front();
            q.pop();

            if(tp -> right != NULL)
                q.push(tp -> right);
            if(tp -> left != NULL)
                q.push(tp -> left);

            temp = tp -> info;
        }

        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);

    vector<int> ans = leftView(root);
    for(int x: ans)
        cout << x << " ";
    cout << "\n";

    deleteTree(root);

    return 0;
}