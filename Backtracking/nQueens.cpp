// N Queens: https://leetcode.com/problems/n-queens/

class Solution 
{
public:
    
    vector<vector<string>> res;
    
    bool isValid(vector<string> &board, int row, int col)
    {
        // Checking the column
        for(int i = row; i >= 0; i--)
            if(board[i][col] == 'Q')
                return false;
    
        // Checking left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        
        // Checking right diagonal
        for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
            if(board[i][j] == 'Q')
                return false;
        
        return true;
    }
    
    void dfs(vector<string> &board, int row)
    {
        if(row == board.size())
        {
            res.push_back(board);
            return;
        }
        
        // Iterating every possible position
        for(int i = 0; i < board.size(); i++)
        {
            if(isValid(board, row, i))
            {
                board[row][i] = 'Q';
                dfs(board, row + 1);        // Recursive call
                board[row][i] = '.';        // Backtracking
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return res;
    }
};


// Optimal Solution
class Solution 
{
public:
    
    vector<vector<string>> res;
    
    bool isValid(vector<string> &board, int row, int col, set<int> &colSet, set<int> &diagSet, set<int> &antidiagSet)
    {
        return !colSet.count(col) && !diagSet.count(row - col) && !antidiagSet.count(row + col);
    }
    
    void dfs(vector<string> &board, int row, set<int> &colSet, set<int> &diagSet, set<int> &antidiagSet)
    {
        if(row == board.size())
        {
            res.push_back(board);
            return;
        }
        
        // Iterating every possible position
        for(int i = 0; i < board.size(); i++)
        {
            if(isValid(board, row, i, colSet, diagSet, antidiagSet))
            {
                board[row][i] = 'Q';
                colSet.insert(i);
                diagSet.insert(row - i);
                antidiagSet.insert(row + i);
                
                dfs(board, row + 1, colSet, diagSet, antidiagSet);          // Recursive call
                
                board[row][i] = '.';                                        // Backtracking
                colSet.erase(i);
                diagSet.erase(row - i);
                antidiagSet.erase(row + i);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        
        set<int> colSet, diagSet, antidiagSet;
        dfs(board, 0, colSet, diagSet, antidiagSet);
        return res;
    }
};