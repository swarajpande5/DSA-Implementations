// https://leetcode.com/problems/remove-duplicate-letters/

class Solution 
{
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> index(26, -1);
        set<char> visited;
        stack<char> st;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++)
            index[s[i] - 'a'] = i;
        
        for(int i = 0; i < n; i++)
        {
            if(visited.count(s[i]))
                continue;
            
            while(!st.empty() && s[i] < st.top() && i < index[st.top() - 'a'])
            {
                visited.erase(st.top());
                st.pop();
            }
            
            st.push(s[i]);
            visited.insert(s[i]);
        }
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

class Solution2 
{
public:
    string removeDuplicateLetters(string s) 
    {
        unordered_map<char, int> freq;
        unordered_map<char, bool> visited;
        string res;
        
        for(char ch: s)
            freq[ch]++;
        
        for(char ch: s)
        {
            freq[ch]--;
            if(visited[ch])
                continue;
            
            while(!res.empty() && res.back() > ch && freq[res.back()] > 0)
            {
                visited[res.back()] = false;
                res.pop_back();
            }
            
            visited[ch] = true;
            res += ch;
        }
        
        return res;
    }
};