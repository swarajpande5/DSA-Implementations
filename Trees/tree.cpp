// Tree Implementation 
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, int source, map<int, vector<int>> tree)
{
    vector<int> distance(n + 1, 0);
    queue<int> q;
    
    q.push(source);
    cout << source << " ";
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto child: tree[curr])
        {
            distance[child] = distance[curr] + 1;
            q.push(child);
            cout << child << " ";
        }
    }
    cout << "\n";

    return distance;
}

vector<int> dfs(int n, int source, map<int, vector<int>> tree)
{
    vector<int> distance(n + 1, 0);
    stack<int> s;

    s.push(source);
    while(!s.empty())
    {
        int curr = s.top();
        s.pop();
        cout << curr << " ";
        for(auto child: tree[curr])
        {
            distance[child] = distance[curr] + 1;
            s.push(child);
        }
    }
    cout << "\n";

    return distance;
}

int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> tree;

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
    }

    cout << "BFS\n";
    vector<int> distance = bfs(n, 1, tree);
    for(int i = 1; i <= n; i++)
        cout << distance[i] << " ";
    cout << "\n";

    cout << "DFS\n";
    distance = dfs(n, 1, tree);
    for(int i = 1; i <= n; i++)
        cout << distance[i] << " ";
    cout << "\n";
}