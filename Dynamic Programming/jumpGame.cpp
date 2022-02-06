// Jump game: https://leetcode.com/problems/jump-game/

/*
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        int reachable = 0;

        for(int i = 0; i < n; i++)
        {
            if(i > reachable)
                return false;
            
            reachable = max(reachable, i + nums[i]);
        }

        return true;
    }
};
*/

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int minjump = 0;
        
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            minjump++;
            
            if(nums[i] >= minjump)
                minjump = 0;
        }

        if(minjump == 0)
            return true;
        else 
            return false;
    }
};