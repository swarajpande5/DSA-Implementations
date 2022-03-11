// All ancestors of a node in a DAG:    https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
//                                      https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/discuss/1822108/C%2B%2B-Solution-or-Plain-DFS-or-Short-and-Clean-code


class Solution
{
public:
    void dfs(int ancestor, int node, vector<vector<int>> &graph, vector<vector<int>> &ans, vector<bool> &visited)
    {
        visited[node] = true;

        for(int child: graph[node])
        {
            if(!visited[child])
            {
                ans[child].push_back(ancestor);
                dfs(ancestor, child, graph, ans, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n), ans(n);

        for(auto &edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        for(int i = 0; i < n; i++)
        {
            vector<bool> vis(n, false);
            dfs(i, i, graph, ans, vis);
        }

        return ans;
    }
};