// All paths from source to target: https://leetcode.com/problems/all-paths-from-source-to-target
//                                  https://leetcode.com/problems/all-paths-from-source-to-target/discuss/118691/C%2B%2BPython-Backtracking
class Solution 
{
public:
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> &path, int curr)
    {
        path.push_back(curr);
        
        if(curr == graph.size() - 1)
            res.push_back(path);
        else
        {
            for(auto it: graph[curr])
                dfs(graph, res, path, it);      // Recursive call
            
        }
        path.pop_back();                        // Backtracking
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, path, 0);
        return paths;
    }
};