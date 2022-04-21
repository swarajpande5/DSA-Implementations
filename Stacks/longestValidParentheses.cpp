// Longest valid parentheses: https://leetcode.com/problems/longest-valid-parentheses/

/*
    Intuition:  1.  First, we iterate through the string, keeping track of the indices of open parentheses in a stack. 
                    Every time we hit a close parenthesis, we know that the last open and the current close are both valid.
                    So we mark both of these as begin valid by overwriting them in the original string with '*'.
                2.  Once we have all of the valid individual parenthesis marked,
                    We iterate through the string once more and identify the longest sequence of '*', which is our answer.
*/

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        stack<int> opens;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                opens.push(i);
            else if(!opens.empty())
            {
                s[opens.top()] = '*';
                s[i] = '*';
                opens.pop();
            }
        }
        
        int curr = 0, res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*')
                curr++;
            else 
            {
                res = max(res, curr);
                curr = 0;
            }
        }
        
        return max(curr, res);
    }
};