// All elements in two binary search trees: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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

    void inorder(TreeNode *root, vector<int> &vec)
    {
        if(root)
        {
            inorder(root -> left, vec);
            vec.push_back(root -> val);
            inorder(root -> right, vec);
        }
    }


    void mergeVectors(vector<int> vec1, vector<int> vec2, vector<int> &mergedVec)
    {
        int i = 0;
        int j = 0;
        int k = 0;

        while(i < vec1.size() && j < vec2.size())
        {
            if(vec1[i] < vec2[j])
                mergedVec[k++] = vec1[i++];
            else 
                mergedVec[k++] = vec2[j++];
        }

        while(i < vec1.size())
            mergedVec[k++] = vec1[i++];
        
        while(j < vec2.size())
            mergedVec[k++] = vec2[j++];
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> t1, t2;
        inorder(root1, t1);
        inorder(root2, t2);

        vector<int> merged(t1.size() + t2.size());
        mergeVectors(t1, t2, merged);

        return merged;
    }
};