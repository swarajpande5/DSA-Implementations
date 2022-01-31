// Climbing stairs: https://leetcode.com/problems/climbing-stairs/

class Solution 
{
public: 
    int climbStairs(int n)
    {
        if(n <= 2)
            return n;
        
        int a, b, res;

        a = 1;
        b = 2;

        for(int i = 3; i <= n; i++)
        {
            res = a + b;
            a = b;
            b = res;
        }

        return res;
    }
};