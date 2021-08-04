// Right View of a Binary Tree : https://leetcode.com/problems/binary-tree-right-side-view/
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

vector<int> rightView(Node *root)
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

            if(tp -> left != NULL)
                q.push(tp -> left);
            if(tp -> right != NULL)
                q.push(tp -> right);
            
            temp = tp -> info;
        }

        ans.push_back(temp);
    }

    return ans;
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
    root->right->left->right = newNode(8);

    vector<int> ans = rightView(root);
    for(int x: ans)
        cout << x << " ";
    cout << "\n";

    deleteTree(root);

    return 0;
}