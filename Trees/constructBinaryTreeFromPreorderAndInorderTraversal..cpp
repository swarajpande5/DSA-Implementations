// Construct binary tree from preorder and inorder traversal:  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    
    // Note: The rootIndex is passed as reference
    TreeNode *buildUtil(vector<int> &preorder, vector<int> &inorder, int &rootIndex, int left, int right, unordered_map<int, int> &hmap)
    {
        if(left > right)
            return NULL; 
    
        int pivot = hmap[preorder[rootIndex]]; 
        TreeNode *node = new TreeNode(inorder[pivot]);      // inorder[pivot] == preorder[rootIndex]
        
        rootIndex++; 
        
        node -> left = buildUtil(preorder, inorder, rootIndex, left, pivot - 1, hmap); 
        
        // rootIndex value get changed after successive calls to build the left subtree. 
        // Hence it must be passed as reference, such that the updated value reaches to build the right subtree.
        
        node -> right = buildUtil(preorder, inorder, rootIndex, pivot + 1, right, hmap);
        
        return node;
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int rootIndex = 0; 
        
        // value -> index mapping for inorder vector
        unordered_map<int, int> hmap;
        
        for(int i = 0; i < inorder.size(); i++)
            hmap[inorder[i]] = i; 
        
        return buildUtil(preorder, inorder, rootIndex, 0, inorder.size() - 1, hmap);
    }
};