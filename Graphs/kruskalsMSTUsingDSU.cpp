// Kruskal's Algorithm for Minimum Spanning Tree using Disjoint Set Union 

#include <bits/stdc++.h>
using namespace std;

struct Edge 
{
    int u, v, wt; 

    node(int _u, int _v, int _wt)
    {
        u = _u;
        v = _v;
        wt = _wt;
    }
};

class DSU 
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int node)
    {
        if(parent[node] == node)
            return node; 
        
        // Path compression
        return parent[node] = findParent(parent[node]);
    }

    void unionNodes(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)
            return; 
        
        // Size optimization
        if(size[pu] < size[pv])
        {    
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else 
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

};

// Comparator function to sort the edges in ascending order according to weight of edge 
bool comp(Edge first, Edge second)
{
    if(first.wt < second.wt)
        return true; 
    
    return false;
}

// Kruskal's algorithm function, which returns {cost, edge vector} of the MST
pair<int, vector<Edge>> kruskal(int n, vector<Edge> &edges) 
{
    sort(edges.begin(), edges.end(), comp); 

    DSU dsu(n); 

    int cost = 0;
    vector<Edge> mstEdges;

    for(auto edge: edges)
    {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt; 

        if(dsu.findParent(u) != dsu.findParent(v))
        {
            dsu.unionNodes(u, v);

            mstEdges.push_back(edge);
            cost += wt;
        }
    }

    return {cost, mstEdges};
}