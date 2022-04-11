// Alien Dictionary: https://practice.geeksforgeeks.org/problems/alien-dictionary/1/

/*
    Intuition:
    The idea is to create a graph, and find the topological sorting of the created graph.

    1.  Create a graph g with number of vertices equal to the size of alphabet in the given alien language.
        Initially there are no edges in graph.
    2.  We do the following for every pair of adjacent word in the given sorted array,
        -   Let the current pair of words be w1 and w2. We one by compare characters of both words and find, 
            the first mismatching characters.
        -   Then we create an edge in g from mismatching character of w1 to that of w2.
    3.  Finally we print the topological sorting of the graph, which is the required answer.
*/

class Solution
{
public:
    
    void topoSort(int src, vector<bool> &visited, vector<int> &topo, vector<int> adj[])
    {
        visited[src] = true;

        for(auto i: adj[src])
            if(!visited[i])
                topoSort(i, visited, topo, adj);
    
        topo.push_back(src);
    }

    
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        
        // Creating the graph
        for(int i = 1; i < N; i++)
        {
            string s1 = dict[i - 1];
            string s2 = dict[i];

            for(int j = 0; j < min(s1.size(), s2.size()); j++)
            {
                // If characters of words mismatch, we simply append a edge in the graph
                if(s1[j] != s2[j])
                {
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adj[u].push_back(v);
                    
                    break;
                }
            }
        }

        vector<bool> visited(K, false);
        vector<int> topo;
        
        for(int i = 0; i < K; i++)
            if(!visited[i])
                topoSort(i, visited, topo, adj);

        reverse(topo.begin(), topo.end());
        string s = "";
        for(int i = 0; i < topo.size(); i++)
            s += topo[i] + 'a';
        
        return s;
    }
};

// TODO: Solve the same question later with Kahn's algorithm