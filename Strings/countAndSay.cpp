// Count and say: https://leetcode.com/problems/count-and-say/

class Solution 
{
public:
    string countAndSay(int n) 
    {
        if (n == 1) 
            return "1";
        
        string res;
        string temp = countAndSay(n-1);     // Recursive call
        char c = temp[0];
        int count = 1;
        
        for (int i = 1; i <= temp.size(); i++) 
        {
            if (temp[i] == c) 
            {
                count++;
            } 
            else 
            {
                res += to_string(count);
                res.push_back(c);
                c = temp[i];
                count = 1;
            }
        }

        return res;
    }
};