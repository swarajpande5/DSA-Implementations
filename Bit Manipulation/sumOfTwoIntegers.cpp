// Sum of two integers: https://leetcode.com/problems/sum-of-two-integers/
// https://leetcode.com/problems/sum-of-two-integers/discuss/1394031/C%2B%2B-oror-100-faster-oror-With-explanation

class Solution 
{
public:
    int getSum(int a, int b) 
    {
        while(b)
        {
            unsigned c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        
        return a;
    }
};