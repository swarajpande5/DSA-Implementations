// Binary tree cameras: https://leetcode.com/problems/binary-tree-cameras/

/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

enum Camera { HAS_CAMERA, COVERED, NOT_COVERED };

class Solution 
{
public:
    
    int cameraCount = 0;
    
    Camera cover(TreeNode *root)
    {
        // Base case, if there is no node then it's already covered
        if(root == NULL)
            return COVERED;
        
        // Try to cover left and right children's subtree
        Camera l = cover(root -> left);
        Camera r = cover(root -> right);
        
        // If any one of the children is not covered then we must place a camera at current node
        if(l == NOT_COVERED || r == NOT_COVERED)
        {
            cameraCount++;
            return HAS_CAMERA;
        }
        
        // If any one of left or right node has Camera then the current node is also covered
        if(l == HAS_CAMERA || r == HAS_CAMERA)
            return COVERED;
        
        // If none of the children is covering the current node, then ask it's parent to cover
        return NOT_COVERED;
    }
    
    int minCameraCover(TreeNode* root) 
    {
        Camera rootStatus = cover(root);
        
        if(rootStatus == NOT_COVERED)
            cameraCount++;
        
        return cameraCount;
    }
    
};