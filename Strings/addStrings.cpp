// Add strings: https://leetcode.com/problems/add-strings/

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // num1 must be smaller than num2
        if(num1.size() > num2.size())
            swap(num1, num2);
        
        string ans = "";
        int carry = 0;

        for(int i = 0; i < num1.size(); i++)
        {
            int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        for(int i = num1.size(); i < num2.size(); i++)
        {
            int sum = (num2[i] - '0') + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if(carry != 0)
            ans.push_back(carry + '0');
        
        reverse(ans.begin(), ans.end());
    
        return ans;
    }
};