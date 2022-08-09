// Class for Disjoint set union by size (-w- path compression)

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