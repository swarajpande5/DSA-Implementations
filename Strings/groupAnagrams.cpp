// Group Anagrams:

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;

        for(int i = 0; i < strs.size(); i++)
        {
            string word = strs[i];
            sort(word.begin(), word.end());

            // Adding the original string to the key which is the sorted string
            m[word].push_back(strs[i]);
        }

        // Finally putting all the values of the map in the result vector 
        for(auto p: m)
            result.push_back(p.second);
        
        return result;
    }
};