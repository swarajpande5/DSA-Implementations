// Backspace string compare: https://leetcode.com/problems/backspace-string-compare/

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {

        stack<char> S, T;

        for (char ch : s)
        {
            if (ch == '#')
            {
                if (!S.empty())
                    S.pop();
            }
            else
                S.push(ch);
        }

        for (char ch : t)
        {
            if (ch == '#')
            {
                if (!T.empty())
                    T.pop();
            }
            else
                T.push(ch);
        }

        return S == T;
    }
};
