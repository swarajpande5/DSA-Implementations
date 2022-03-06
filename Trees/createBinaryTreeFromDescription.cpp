// Create binary tree from descriptions: 

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> getNode;          // To check if node already exists or not
        unordered_map<int, bool> isChild;               // To check if node has parent or not

        for(auto d: descriptions)
        {
            int parent = d[0];
            int child = d[1];
            int isleft = d[2];

            if(getNode.count(parent) == 0)
            {
                TreeNode *p = new TreeNode(parent);
                getNode[parent] = p;
            }

            if(getNode.count(child) == 0)
            {
                TreeNode *c = new TreeNode(child);
                getNode[child] = c;
            }

            if(isleft)
                getNode[parent] -> left = getNode[child];
            else 
                getNode[parent] -> right = getNode[child];
            
            isChild[child] = true;
        }

        TreeNode *ans = NULL;
        for(auto d: descriptions)
        {
            int parent = d[0];

            if(isChild[parent] != true)
            {
                ans = getNode[parent];
                break;
            }
        }

        return ans;
    }
};