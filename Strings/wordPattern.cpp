// Word pattern: 

class Solution 
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> v;
        string word;
        stringstream iss(s);

        // Push each word in vector
        while(iss >> word)
            v.push_back(word);
        
        set<string> S;              // To check if the same word is not mapped with another character

        if(pattern.size() != v.size())
            return false; 
        
        unordered_map<char, string> m;
        for(int i = 0; i < pattern.size(); i++)
        {
            char ch = pattern[i];

            // If current character is present in the map 
            if(m.find(ch) != m.end())
            {
                // Check if the string mapped to taht character is different or not 
                // if yes return false 
                if(m[ch] != v[i])
                    return false;
            }

            // If not present in map 
            else 
            {
                // Check if the string is previously in set
                // If it is in set it means it is already mapped return false 
                if(S.count(v[i]) > 0)
                    return false; 
                
                // otherwise simply insert into map an dset 
                m[ch] = v[i];
                S.insert(v[i]);
            }
        }

        return true;
    }
};