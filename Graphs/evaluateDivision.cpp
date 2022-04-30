// Evaluate division: https://leetcode.com/problems/evaluate-division/

class Solution 
{
public:
    
    void createGraph(unordered_map<string, unordered_map<string, double>> &graph, vector<vector<string>> &equations, vector<double> &values)
    {
        for(int i = 0; i < equations.size(); i++)
        {
            string numerator = equations[i][0];
            string denominator = equations[i][1];
            double value = values[i];
            
            graph[numerator][denominator] = value;
            graph[denominator][numerator]= 1.0 / value;
        }
    }
    
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited)
    {
        if(graph.find(start) == graph.end())
            return -1;
        
        if(graph[start].find(end) != graph[start].end())
            return graph[start][end];
        
        visited.insert(start);
        
        for(auto nbr: graph[start])
        {
            if(!visited.count(nbr.first))
            {
                double ans = dfs(nbr.first, end, graph, visited);
                
                if(ans != -1.0)
                    return ans * (nbr.second);
            }
        }
    
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, unordered_map<string, double>> graph;
        
        createGraph(graph, equations, values);
        
        vector<double> ans(queries.size());
        
        for(int i = 0; i < queries.size(); i++)
        {
            unordered_set<string> visited;
            ans[i] = dfs(queries[i][0], queries[i][1], graph, visited);
        }
        
        return ans;
    }
};