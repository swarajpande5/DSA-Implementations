// Reorganize string: https://leetcode.com/problems/reorganize-string/

class Solution 
{
public:
    struct comp
    {
        bool operator()(pair<char, int> p1, pair<char, int> p2)
        {
            if(p1.second < p2.second)
                return true;
            return false;
        }
    };
    
    string reorganizeString(string s) 
    {
        unordered_map<char, int> mp;
        for(auto ch: s)
            mp[ch]++;
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        
        for(auto p: mp)
            pq.push(p);
    
        string res = "";
        while(pq.size() > 1)
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            res += top1.first;
            res += top2.first;
            
            top1.second -= 1;
            top2.second -= 1;
            
            if(top1.second > 0)
                pq.push(top1);
            if(top2.second > 0)
                pq.push(top2);
        }
        
        if(!pq.empty())
        {
            if(pq.top().second > 1)
                return "";
            else 
                res += pq.top().first;
        }
        
        return res;
    }
};