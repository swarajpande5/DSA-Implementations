// Naming a company: https://leetcode.com/problems/naming-a-company/
// https://leetcode.com/problems/naming-a-company/discuss/2140967/Count-Pairs

class Solution 
{
public:
    long long distinctNames(vector<string>& ideas) 
    {
        long long res = 0;
        long long cnt[26][26] = {0};
        
        vector<unordered_set<string>> s(26);
        
        for(auto idea: ideas)
            s[idea[0] - 'a'].insert(idea.substr(1));
        
        for(int i = 0; i < 26; i++)
            for(auto suffix: s[i])
                for(int j = 0; j < 26; j++)
                    cnt[i][j] += (s[j].count(suffix) == 0);
        
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                res += cnt[i][j] * cnt[j][i];
        
        return res;
    }
};