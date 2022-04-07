// Sudoku Solver: https://leetcode.com/problems/sudoku-solver/

class Solution 
{
public:
    
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        // Row check
        for(int i = 0; i < 9; i++)
            if(board[i][col] == c)
                return false;
        
        // Column check
        for(int i = 0; i < 9; i++)
            if(board[row][i] == c)
                return false;
        
        // 3x3 box check
        int x0 = (row / 3) * 3;
        int y0 = (col / 3) * 3;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(board[x0 + i][y0 + j] == c)
                    return false;
        
        return true;
    }
    
    bool util(vector<vector<char>> &board, int row, int col)
    {
        // If row == 9, then end the process
        if(row == 9)
            return true;
        
        if(col == 9)
            return util(board, row + 1, 0);
        
        // If already marked
        if(board[row][col] != '.')
            return util(board, row, col + 1);
        
        for(char c = '1'; c <= '9'; c++)
        {
            if(isValid(board, row, col, c))
            {
                board[row][col] = c;
                
                if(util(board, row, col + 1))
                    return true;
                
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>> &board) 
    {
        util(board, 0, 0);     
    }
};