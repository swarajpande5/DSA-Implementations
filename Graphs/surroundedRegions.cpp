// Surrounded Regions: https://leetcode.com/problems/surrounded-regions/
                       https://leetcode.com/problems/surrounded-regions/discuss/1551810/Fast-and-very-easy-to-understand-or-DFS-from-borders-or-O(N)-time-or-O(N)-Space

class Solution 
{
    int n, m;
    
public:
    
    void dfs(int row, int col, vector<vector<char>> &board)
    {
        board[row][col] = 'R';
        
        if(row > 0 && board[row - 1][col] == 'O')
            dfs(row - 1, col, board);
        
        if(row < n - 1 && board[row + 1][col] == 'O')
            dfs(row + 1, col, board);
        
        if(col > 0 && board[row][col - 1] == 'O')
            dfs(row, col - 1, board);
        
        if(col < m - 1 && board[row][col + 1] == 'O')
            dfs(row, col + 1, board);
    }
    
    void solve(vector<vector<char>>& board) 
    {
        n = board.size();
        m = board[0].size();
        
        if (n < 3 || m < 3) 
            return;
        
        for (auto row = 0; row < n; ++row) 
        {
            if (board[row][0] == 'O') 
                dfs(row, 0, board);
            
            if (board[row][m - 1] == 'O') 
                dfs(row, m - 1, board);
        }
        
        for (auto col = 1; col < m - 1; ++col) 
        {
            if (board[0][col] == 'O') 
                dfs(0, col, board);

            if (board[n - 1][col] == 'O') 
                dfs(n - 1, col, board);
        }
        
        for (auto row = 0; row < n; ++row) 
        {
            for (auto col = 0; col < m; ++col) 
            {
                if (board[row][col] == 'O') 
                    board[row][col] = 'X';
                
                else if (board[row][col] == 'R') 
                    board[row][col] = 'O';
    
            }
        }
    }
};