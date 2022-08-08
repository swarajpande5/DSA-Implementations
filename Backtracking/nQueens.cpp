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


// GFG Question: https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
// To print all possible solution of the N-Queens problem 

class Solution
{
public:

    vector<vector<int>> res; 
    
    bool isValid(vector<vector<int>> &board, int row, int col, set<int> &colSet, set<int> &diagSet, set<int> &antidiagSet)
    {
        return !colSet.count(col) && !diagSet.count(row - col) && !antidiagSet.count(row + col);
    }

    bool dfs(vector<vector<int>> &board, int row, set<int> &colSet, set<int> &diagSet, set<int> &antidiagSet)
    {
        if(row == board.size())
        {
            vector<int> v;
            for(int i = 0; i < board.size(); i++)
                for(int j = 0; j < board[0].size(); j++)
                    if(board[i][j] == 1)
                        v.push_back(j + 1);
            
            res.push_back(v);
            return true;
        }
        
        bool check = false; 
        for(int i = 0; i < board.size(); i++)
        {
            if(isValid(board, row, i, colSet, diagSet, antidiagSet))
            {
                board[row][i] = 1;
                colSet.insert(i);
                diagSet.insert(row - i);
                antidiagSet.insert(row + i);
                
                check = dfs(board, row + 1, colSet, diagSet, antidiagSet) || check;          // Recursive call
                
                board[row][i] = 0;                                        // Backtracking
                colSet.erase(i);
                diagSet.erase(row - i);
                antidiagSet.erase(row + i);
            }
        }
        
        return check;
    }

    vector<vector<int>> nQueen(int n) 
    {
        res.clear(); 
        vector<vector<int>> board(n, vector<int>(n, 0));
        set<int> colSet, diagSet, antidiagSet;
        
        if(dfs(board, 0, colSet, diagSet, antidiagSet) == false)
            return {};
        
        sort(res.begin(), res.end());
        return res;
        
    }
};