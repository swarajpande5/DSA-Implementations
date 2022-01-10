// Add binary: https://leetcode.com/problems/add-binary/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        // We start adding digits from last, as normal binary addition works
        int i = a.size() - 1;
        int j = b.size() - 1;

        string ans = "";
        int carry = 0;

        while(i >= 0 || j >= 0 || carry > 0)
        {
            if(i >= 0)
            {
                carry += a[i] - '0';        // calculating carry at a[i];
                i--;
            }

            if(j >= 0)
            {
                carry += b[j] - '0';        // calculating carry at b[j];
                j--;
            }

            ans += (carry % 2) + '0';       // carry values can be 0, 1, 2 so we mod the value
            carry /= 2;                     // carry is propagated forward, if it equal to two, hence we divide the carry by two.
        }

        reverse(ans.begin(), ans.end());    // Finally we reverse our answer, as we started from last 

        return ans;
    }
};