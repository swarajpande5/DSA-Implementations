// The Skyline problem: https://leetcode.com/problems/the-skyline-problem/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<vector<int>> ans; 
        multiset<int> pq = {0}; 
        
        vector<pair<int, int>> points; 
        
        for(auto b: buildings) {
            points.push_back({b[0], -b[2]}); 
            points.push_back({b[1], b[2]});
        }
        
        sort(points.begin(), points.end()); 
        
        int ongoingHeight = 0; 
        
        for(int i = 0; i < points.size(); i++) {
            int currPoint = points[i].first; 
            int currHeight = points[i].second; 
            
            if(currHeight < 0) {
                pq.insert(-currHeight);
            }
            else {
                pq.erase(pq.find(currHeight));
            }
            
            auto top = *pq.rbegin(); 
            if(ongoingHeight != top) {
                ongoingHeight = top; 
                ans.push_back({currPoint, ongoingHeight});
            }
        }
        
        return ans;
    }
};