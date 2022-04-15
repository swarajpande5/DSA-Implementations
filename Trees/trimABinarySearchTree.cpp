// Trim a binary search tree: https://leetcode.com/problems/trim-a-binary-search-tree/
//                            https://leetcode.com/problems/trim-a-binary-search-tree/discuss/501234/C%2B%2B%3A-Detailed-explanation.-Recursive-Approach

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
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(!root)
            return NULL;
        
        if(root -> val >= low && root -> val <= high)
        {
            root -> left = trimBST(root -> left, low, high);
            root -> right = trimBST(root -> right, low, high);
            return root;
        }

        // When current node's value is less than low
        if(root -> val < low)
            return trimBST(root -> right, low, high);
        
        // When current node's value is greater than high
        return trimBST(root -> left, low, high);
    }
};