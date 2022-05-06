// Remove all adjacent duplicates in string 2: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution 
{
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char, int>> st;
        
        for(auto &ch: s)
        {
            if(st.empty() || st.top().first != ch)
            {
                st.push({ch, 1});
            }
            else 
            {
                st.push({ch, st.top().second + 1});
                
                if(st.top().second >= k)
                {
                    int i = st.top().second;
                    while(i--)
                        st.pop();
                }
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans += st.top().first;
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};