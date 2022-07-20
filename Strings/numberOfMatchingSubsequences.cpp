// Number of matching subsequences: https://leetcode.com/problems/number-of-matching-subsequences/
// https://leetcode.com/problems/number-of-matching-subsequences/discuss/1289527/Number-of-Matching-Subsequences-or-Easy-Solution-w-Explanation-or-Binary-Search

// Naive Solution (T.C. = O(nnm))
class NaiveSolution 
{
public:
    
    int isSubsequence(string a, string b)
    {
        int i = 0, j = 0;
        int m = a.length(), n = b.length(); 
        
        while(i < m && j < n)
        {
            if(a[i] == b[j])
            {
                i++; 
                j++;
            }
            else 
                i++;
        }
        
        if(j == n)
            return true; 
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int count = 0; 
        unordered_map<string, int> mp; 
        
        for(string word: words)
            mp[word]++; 
        
        for(auto p: mp)
        {
            if(isSubsequence(s, p.first))
                count += p.second;
        }
        
        return count;
    }
};


// Optimal Solution (T.C. = O(l + nmlog(l)))
class Solution
{
public: 
    int numMatchingSubseq(string &s, vector<string> &words)
    {
        int count = 0; 
        
        // Stores array of indices for each character in s
        vector<vector<int>> mappings(26);
        for(int i = 0; i < s.size(); i++)
            mappings[s[i] - 'a'].push_back(i); 
        
        for(string &word: words)
        {
            bool found = true; 
            
            // i -> index in word 
            // prev -> index in s matched for word[i - 1]
            for(int i = 0, prev = -1; found && i < word.size(); i++)
            {
                auto &v = mappings[word[i] - 'a']; 
                
                // Checking if current character exists in s with index > prev
                auto it = upper_bound(v.begin(), v.end(), prev);
                if(it == v.end())
                    found = false; 
                else 
                    prev = *it;     // Updated the prev for next character check
            }
            
            count += found;
        }
        
        return count;
    }
};