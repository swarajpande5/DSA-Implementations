// Tree serialization and deserialization: https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

/* A binary tree node has data, pointer to left child
    and a pointer to right child

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    void inOrder(Node *node, vector<int> &res)
    {
        if (node == NULL)
        {
            res.push_back(-1);
            return;
        }

        res.push_back(node->data);
        inOrder(node->left, res);
        inOrder(node->right, res);
    }

    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> res;
        inOrder(root, res);
        return res;
    }

    // Function to construct the tree
    Node *construct(vector<int> &a, int *index)
    {
        // If there are no elements in the list
        if (*index == a.size() || a[*index] == -1)
        {
            *index += 1;
            return NULL;
        }

        // Creating new node for storing the current element
        Node *root = new Node(a[*index]);
        *index += 1;

        // Calling function recursively for left and right subtrees
        root->left = construct(a, index);
        root->right = construct(a, index);

        return root;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        int index = 0;
        return construct(A, &index);
    }
};

// Leetcode: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string of preorder traversal.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "null";

        string s;
        s += to_string(root->val);

        string serialLeft = serialize(root->left);
        string serialRight = serialize(root->right);

        return s + "," + serialLeft + "," + serialRight;
    }

    TreeNode *deserializeUtility(queue<string> &q)
    {
        if (q.empty())
            return NULL;

        string s = q.front();
        q.pop();

        if (s == "null")
            return NULL;

        int num = stoi(s);

        TreeNode *node = new TreeNode(num);
        node->left = deserializeUtility(q);
        node->right = deserializeUtility(q);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<string> q;
        string temp;

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ',')
            {
                q.push(temp);
                temp = "";
            }

            else
                temp.push_back(data[i]);
        }

        return deserializeUtility(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));