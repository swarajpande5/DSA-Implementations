// Ugly Number 2: https://leetcode.com/problems/ugly-number-ii/
class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        vector<int> ugly = {1}; 
        int last = 1; 
        
        int d2, d3, d5; 
        d2 = 2, d3 = 3, d5 = 5; 
        
        int i2, i3, i5; 
        i2 = i3 = i5 = 0; 
        
        while(ugly.size() < n)
        {
            while(d2 <= last)
            {
                d2 = 2 * ugly[i2]; 
                i2++;
            }
            
            while(d3 <= last)
            {
                d3 = 3 * ugly[i3]; 
                i3++;
            }
            
            while(d5 <= last)
            {
                d5 = 5 * ugly[i5];
                i5++;
            }
            
            last = min({d2, d3, d5});
            ugly.push_back(last);
        }
        
        return ugly[n - 1];
    }
};