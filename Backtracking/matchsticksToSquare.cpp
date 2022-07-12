// Matchsticks to square: https://leetcode.com/problems/matchsticks-to-square/

// Variation of Partition to k equal sum subsets: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution 
{
public: 

    bool solve(vector<int> &matchsticks, int index, vector<int> &sides)
    {
        if(idx == matchsticks.size())
            return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0; 
        
        for(int i = 0; i < 4; i++)
        {
            // If the length of matchstick exceeds that length of a side, we simply continue and do not make any further calls.
            if(sides[i] < matchsticks[index])
                continue; 
            
            sides[i] -= matchsticks[index]; 
            if(solve(matchsticks, index + 1, sides))
                return true; 
            sides[i] += matchsticks[index];
        }

        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0); 
        
        if(perimeter % 4 != 0)
            return false; 
        
        int sideLength = perimeter / 4; 
        vector<int> sides(4, side); 
        
        // Sorting will help us eliminate the long sticks immediately.
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); 

        return solve(matchsticks, 0, sides);
    }
};