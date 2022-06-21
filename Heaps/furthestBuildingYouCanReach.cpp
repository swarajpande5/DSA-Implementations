// Furthest building you can reach: https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution 
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0; i < heights.size() - 1; i++)
        {
            int dist = heights[i + 1] - heights[i];
            
            // When we need to climb, we always assume that we are using ladder 
            if(dist > 0)
                minHeap.push(dist);
            
            // When we can't use ladder, i.e. when heap size exceeds number of ladders.     
            // We try to cover the smallest distance with the bricks
            
            if(minHeap.size() > ladders)
            {
                bricks -= minHeap.top();
                minHeap.pop();
            }
            
            // If we run out of bricks, then we are done moving up
            if(bricks < 0)
                return i;
        }
        
        return heights.size() - 1;
    }
};