// Possible bipartition: https://leetcode.com/problems/possible-bipartition/description/

class Solution {
public:

    bool possibleToColor(int node, int newColor, vector<int> graph[], vector<int> &color) {
        color[node] = newColor; 
        for(auto nbr: graph[node]) {
            if(color[nbr] == -1)
                possibleToColor(nbr, 1 - newColor, graph, color); 
            else if(color[nbr] == color[node])
                return false; 
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n + 1]; 
        for(auto dislike: dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }

        vector<int> color(n + 1, -1); 
        for(int i = 0; i < n; i++) {
            if(color[i] == -1)
                if(!possibleToColor(i, 1, graph, color)) 
                    return false; 
        }

        return true;
    }
};