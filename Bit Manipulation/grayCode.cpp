// Gray Code: https://leetcode.com/problems/gray-code/

class Solution 
{
public:
    vector<int> grayCode(int n) 
    {
        vector<int> res;
        res.push_back(0);
        
        for(int i = 1; i <= n; i++)
        {
            int prevLength = res.size();
            int mask = 1 << (i - 1);
            
            for(int j = prevLength - 1; j >= 0; j--)
                res.push_back(mask + res[j]);
        }
        
        return res;
    }
};