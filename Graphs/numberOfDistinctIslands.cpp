// Number of distinct islands: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

// Approach 1

// X = start
// O = out of bounds or water
// L = left
// R = right
// U = up
// D = down

/*
    Logic:  Whenever we encounter a land, we initiate the dfs call.
            We construct a string of how we visited all the nodes in that
            connected component of island by using the above convention.
            We then count all those unique strings by storing them in a set.
*/

class Solution
{
public:
    // DFS method to generate the island blueprint string
    string getIslandBlueprint(vector<vector<int>> &grid, int i, int j, string start)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return "O";

        // Marking the current cell as visited
        grid[i][j] = 0;

        string left = getIslandBlueprint(grid, i, j - 1, "L");
        string right = getIslandBlueprint(grid, i, j + 1, "R");
        string up = getIslandBlueprint(grid, i - 1, j, "U");
        string down = getIslandBlueprint(grid, i + 1, j, "D");

        return start + left + right + up + down;
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        set<string> islands;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    string blueprint = getIslandBlueprint(grid, i, j, "X");
                    islands.insert(blueprint);
                }
            }
        }

        return islands.size();
    }
};

// Approach 2

/*
    Logic:  We record the coordinate difference of all the cells which form an island,
            and store those coordinate differences in a set. Finally we return the set size.
*/
class Solution
{
public:
    // DFS method to generate the island blueprint string
    void dfs(vector<vector<int>> &grid, int i, int j, int startX, int startY, vector<pair<int, int>> &currCoordinates)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;

        // Pushing the current cell difference and marking the current cell as visited
        currCoordinates.push_back({i - startX, j - startY});
        grid[i][j] = 0;

        dfs(grid, i, j + 1, startX, startY, currCoordinates);
        dfs(grid, i, j - 1, startX, startY, currCoordinates);
        dfs(grid, i + 1, j, startX, startY, currCoordinates);
        dfs(grid, i - 1, j, startX, startY, currCoordinates);
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        set<vector<pair<int, int>>> coordinates;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    vector<pair<int, int>> currCoordinates;
                    dfs(grid, i, j, i, j, currCoordinates);
                    coordinates.insert(currCoordinates);
                }
            }
        }

        return coordinates.size();
    }
};
