// Delete node in a BST: https://leetcode.com/problems/delete-node-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution 
{
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)
            return NULL; 
        
        // Finding the key node
        if(key < root -> val)
            root -> left = deleteNode(root -> left, key); 
        else if(key > root -> val)
            root -> right = deleteNode(root -> right, key); 
        
        // When we find the key node
        else 
        {
            // If the key node is a leaf node, we simply return NULL 
            if(!root -> left && !root -> right)
                return NULL; 
            
            // If the key node has only one child, we replace the node with its child
            if(!root -> left || !root -> right)
                return root -> left ? root -> left : root -> right;
            
            // If the key node has two children, we need to replace the node with 
            // its inorder successor (the next node that comes in the inorder)
            // Hence, we need to replace the key node with either, 
            // 1. The greatest value in it's left subtree (or)
            // 2. The smallest value in it's right subtree 
            // and return the root. 
            
            TreeNode *temp = root -> left; 
            while(temp -> right != NULL)
                temp = temp -> right; 
            
            root -> val = temp -> val; 
            root -> left = deleteNode(root -> left, temp -> val);
        }
        
        return root;
    }
};