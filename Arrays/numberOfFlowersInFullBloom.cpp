// Number of flowers in full bloom: https://leetcode.com/problems/number-of-flowers-in-full-bloom/

/*
    Intuition:
    Blooming flowers = started flowers - ended flowers 
    1.  First we sort start and end bloom times individually.
    2.  For each time point in t in persons:
        -   Binary search the upper bound of t in start, we found the started flowers
        -   Binary search the lower bound of t in end, we found the ended flowers 
        -   Blooming flowers = started flowers - ended flowers
*/

class Solution 
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) 
    {
        vector<int> start, end;
        
        for(auto p: flowers)
        {
            start.push_back(p[0]);
            end.push_back(p[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        vector<int> res;
        
        for(int t: persons)
        {
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            
            res.push_back(started - ended);
        }
        
        return res;
    }
};