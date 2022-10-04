// Find Duplicate Subtrees: https://leetcode.com/problems/find-duplicate-subtrees/
// https://leetcode.com/problems/find-duplicate-subtrees/discuss/106055/C%2B%2B-Java-Clean-Code-with-Explanation

/*
    Analysis:   
        1.  A unique subtree can be uniquely identified by its serialized string. 
        2.  Using postorder traversal we can gradually collect all unique tree-serializations with their associated nodes.
        3.  Then we can see if there is any serialization is associated with more than 1 subtree nodes, 
            then we know that there is duplicated subtree nodes.

*/

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
class Solution {
public:
    string serialize(TreeNode *root, unordered_map<string, vector<TreeNode *>> &map)
    {
        if(!root)
            return ""; 

        string s = "(" + serialize(root -> left, map) + to_string(root -> val) + serialize(root -> right, map) + ")"; 
        map[s].push_back(root);

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string, vector<TreeNode *>> map; 
        vector<TreeNode *> dups; 

        serialize(root, map); 

        for(auto p: map)
        {
            if(p.second.size() > 1)
                dups.push_back(p.second[0]);
        }

        return dups;
    }
};