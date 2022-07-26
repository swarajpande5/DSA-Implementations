// Step by step direction from a binary tree node to another: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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

/*
Approach: 
    1. Apply LCA to get the new root 
    2. Get the path from new root to start and destination
    3. Concatenate the two paths, wherein start node's path must be replaced to U
*/

class Solution 
{
public:
    
    TreeNode* lca(TreeNode *root, int &startValue, int &destValue)
    {
        if(root == NULL || root -> val == startValue || root -> val == destValue)
            return root; 
        
        TreeNode *left = lca(root -> left, startValue, destValue);
        TreeNode *right = lca(root -> right, startValue, destValue); 
        
        if(left == NULL)
            return right; 
        else if(right == NULL)
            return left; 
        else 
            return root;
    }
    
    bool getPath(TreeNode *root, int value, string &path)
    {
        if(!root)
            return false; 
        
        if(root -> val == value)
            return true; 
        
        path += 'L';
        bool res = getPath(root -> left, value, path); 
        if(res)
            return true; 
        
        path.pop_back(); 
        path += 'R';
        res = getPath(root -> right, value, path);
        if(res)
            return true; 
        
        path.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode *newRoot = lca(root, startValue, destValue);
        
        string p1, p2;
        getPath(newRoot, startValue, p1);
        getPath(newRoot, destValue, p2);
        
        for(auto &c: p1)
            c = 'U';
        
        return p1 + p2;
    }
};