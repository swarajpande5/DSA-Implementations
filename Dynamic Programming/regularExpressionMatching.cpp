// Regular expression matching: https://leetcode.com/problems/regular-expression-matching/
//                              https://leetcode.com/problems/regular-expression-matching/discuss/1570688/C%2B%2B-solution-with-different-approaches

// Recursive solution
class RecursiveSolution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();

        bool firstChar = !s.empty() && ((p[0] == s[0]) || (p[0] == '.'));

        if (p.length() >= 2 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (firstChar && isMatch(s.substr(1), p));
        else
            return firstChar && isMatch(s.substr(1), p.substr(1));
    }
};

// Top Down Solution (Memoization)
class TopDownDPSolution
{
public:
    bool dp(int i, int j, string s, string p, vector<vector<int>> &memo)
    {
        if (memo[i][j] != -1)
            return memo[i][j] == 1;

        bool ans;
        if (j == p.length())
            ans = (i == s.length());
        else
        {
            bool firstChar = (i < s.length() && (p[j] == s[i] || p[j] == s[i] || p[j] == '.'));
            if (j + 1 < p.length() && p[j + 1] == '*')
                ans = (dp(i, j + 2, s, p, memo) || (firstChar && dp(i + 1, j, s, p, memo)));
            else
                ans = firstChar && dp(i + 1, j + 1, s, p, memo);
        }

        memo[i][j] = ans ? 1 : 0;
        return ans;
    }

    bool isMatch(string s, string p)
    {
        vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dp(0, 0, s, p, memo);
    }
};

// Cheeky solution
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return regex_match(s, regex(p));
    }
};