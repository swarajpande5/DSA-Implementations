// Zigzag conversion:   https://leetcode.com/problems/zigzag-conversion/
//                      https://leetcode.com/problems/zigzag-conversion/discuss/1492755/C%2B%2B-Easy-to-understand-or-With-Explanation-or-Clean-code
class Solution 
{
public:
    string convert(string s, int rows) 
    {
        if(rows == 1)
            return s;
    
        vector<string> vec(rows);
        
        bool down = false;
        int j = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            vec[j].push_back(s[i]);
            
            if(j == rows - 1)
                down = false;
            else if(j == 0)
                down = true;
            
            if(down == true)
                j++;
            else
                j--;
        }
        
        string res = "";
        for(auto e: vec)
            res += e;
        
        return res;
    }
};