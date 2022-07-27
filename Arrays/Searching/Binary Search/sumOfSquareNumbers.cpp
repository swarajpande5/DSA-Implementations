// Sum of square numbers: https://leetcode.com/problems/sum-of-square-numbers/

class Solution 
{
public:
    bool isPerfectSquare(long int n) 
    {
        if(n == 1 || n == 0)
            return true;
        long int s = 0, e = n;
        
        while(s <= e)
        {
            long int m = s + (e - s)/2;
            if(m*m == n)
                return true;
            else if(m*m < n)
                s = m + 1;
            else e = m - 1;
        }
        
        return false;
    }
    
    bool judgeSquareSum(int c) 
    {
        
        if(c == 1 || c == 0)
            return true;
        
        for(long int i = 0; i*i <= c; i++)
        {
            long int x = i*i;
            if (isPerfectSquare(c-x))
                return true;
        }
        return false;
    }
};