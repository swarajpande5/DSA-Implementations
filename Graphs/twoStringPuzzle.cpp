/*
    Return the minimum operations to convert string s1 to s2 (of equal lengths), 
    where the operations are defined as follows,
    - A character k can be changed to k + 1, except z.
    - A character k can be changed to 25 - pos(k).
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v = 26;
    int inf = 1e7;

    vector<vector<int>> graph(v, vector<int>(v, inf));
    
    // Generating adjacency matrix
    for(int i = 0; i < v; i++)
        graph[i][i] = 0;

    for(int i = 0; i < v - 1; i++)
        graph[i][i + 1] = 1;
    
    for(int i = 0; i < (v - 1) / 2; i++)
    {    
        graph[i][25 - i] = 1;
        graph[25 - i][i] = 1;
    }

    graph[12][13] = 1;
    graph[13][12] = 1;

    // Applying floyd warshall
    int dist[v][v];

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            dist[i][j] = graph[i][j];

    for(int k = 0; k < v; k++)
    {
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != inf && dist[i][k] != inf))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    // Displaying the dist matrix

    // cout << "   ";
    // for(int i = 0; i < v; i++)
    //     cout << setw(3) << char('a' + i);
    // cout << endl;

    // for(int i = 0; i < v; i++)
    // {
    //     cout << setw(3) << (char)('a' + i);
    //     for(int j  = 0; j < v; j++)
    //         cout << setw(3) << dist[i][j];
    //     cout << endl;
    // }

    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int n = s1.length();
        int count = 0;

        for(int i = 0; i < n; i++)
            count += dist[s1[i] - 'a'][s2[i] - 'a'];

        cout << count << endl;
    }

    return 0;
}