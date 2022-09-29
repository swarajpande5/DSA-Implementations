// Fraction to recurring decimal: https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution 
{
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        if(!numerator)
            return "0"; 
        
        string ans; 
        if(numerator > 0 ^ denominator > 0)
            ans += '-'; 
        
        long n = labs(numerator); 
        long d = labs(denominator); 
        long r = n % d; 
        
        ans += to_string(n / d); 
        
        if(!r)
            return ans; 
        
        ans += '.'; 
        
        // Is the remainder seen before
        unordered_map<long, int> rs;
        
        while(r)
        {
            if(rs.find(r) != rs.end())
            {
                ans.insert(rs[r], "("); 
                ans += ')'; 
                break;
            }
            
            rs[r] = ans.size(); 
            r *= 10; 
            ans += to_string(r / d); 
            r %= d; 
        }
        
        return ans;
    }
};