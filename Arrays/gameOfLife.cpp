// Game of life: https://leetcode.com/problems/game-of-life/

class Solution 
{
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int>> neighbors = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };
        
        // If a cell is 1,
        //  neighbors < 2, it dies
        //  neighbors = [2, 3], it lives
        //  neighbors > 3, it dies
        
        // If a cell is 0,
        //  neighbors = 3, it becomes alive
        
        // In order to avoid extra space,
        //  0 ==> 0 in both original and new matrix (it was dead and still dead)
        //  1 ==> 1 in both original and new matrix (it was alive and still alive)
        //  2 ==> 0 in original matrix, 1 in new matrix (it was dead, but now alive)
        //  3 ==> 1 in original matrix, 0 in new matrix (it was alive, but now dead)
        
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                int live = 0;
                
                for(vector<int> n: neighbors)
                {
                    int rr = r + n[0];
                    int cc = c + n[1];
                    
                    if(rr >= 0 && rr < rows && cc >= 0 && cc < cols)
                        live += (board[rr][cc] == 1 || board[rr][cc] == 3) ? 1 : 0;
                }
                
                if(board[r][c] == 0 && live == 3)
                    board[r][c] = 2;
                else if(board[r][c] == 1)
                    board[r][c] = (live < 2 || live > 3) ? 3 : 1;
            }
        }
        
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(board[r][c] == 2)
                    board[r][c] = 1;
                if(board[r][c] == 3)
                    board[r][c] = 0;
            }
        }
    }
};