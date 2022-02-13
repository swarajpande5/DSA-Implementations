// Repeated DNA sequences: https://leetcode.com/problems/repeated-dna-sequences/

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> counter;
        vector<string> res;

        if(s.size() < 10)
            return res; 
        
        for(int i = 0; i < s.size() - 9; i++)
            counter[s.substr(i, 10)]++;
        
        for(auto p: counter)
            if(p.second > 1)
                res.push_back(p.first);
    
        return res;
    }
};