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
    
    int maxDepth;
    
    int maxDepthUtil(TreeNode *root)
    {
        if(!root)
            return 0;
        return max(maxDepthUtil(root -> left) + 1, maxDepthUtil(root -> right) + 1);
    }
    
    int sumUtil(TreeNode *root, int depth)
    {
        if(!root)
            return 0;
        
        if(depth == maxDepth - 1)
            return root -> val;
        
        return sumUtil(root -> left, depth + 1) + sumUtil(root -> right, depth + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) 
    {
        maxDepth = maxDepthUtil(root);
        return sumUtil(root, 0);
    }
};

class LevelOrderSolution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        int res = 0;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            res = 0;
            for(int i = q.size() - 1; i >= 0; i--)
            {
                TreeNode *node = q.front();
                q.pop();

                res += node -> val;

                if(node -> right)
                    q.push(node -> right);
                if(node -> left)
                    q.push(node -> left);
            }
        }

        return res;
    }
};