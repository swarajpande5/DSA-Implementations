// Shortest path visiting all nodes:    https://leetcode.com/problems/shortest-path-visiting-all-nodes/
//                                      https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/1755951/C%2B%2B-or-BFS-or-Beginner-friendly

class Solution
{
public:
    int shortestPathLength(vector<vector<int>>& graph)
    {
        int n = graph.size();
        int ans = 0;

        queue<vector<int>> q;
        set<pair<int, int>> s;

        // Starting BFS from every node and mask is used to check state of all visited nodes
        for(int i = 0; i < n; i++)
        {
            vector<int> v(3, 0);
            int cost = 0;
            int node = i;
            int mask = 1 << i;

            v[0] = cost;
            v[1] = node;
            v[2] = mask;

            q.push(v);
            s.insert({node, mask});
        }

        // BFS
        while(!q.empty())
        {
            auto z = q.front();
            q.pop();

            // If all bits are set, it means that all nodes are finally visited
            if(z[2] == (1 << n) - 1)
            {
                ans = z[0];
                break;
            }

            for(auto j: graph[z[1]])
            {
                int mask = z[2] | (1 << j);

                // Checking whether this state is visited or not 
                if(s.find({j, mask}) == s.end())
                {
                    s.insert({j, mask});

                    vector<int> v(3, 0);
                    v[0] = z[0] + 1;
                    v[1] = j;
                    v[2] = mask;

                    q.push(v);
                }
            }
        }

        return ans;
    }
};