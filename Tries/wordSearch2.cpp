// Word Search 2: https://leetcode.com/problems/word-search-ii/

// Approach: Trie + Backtracking

class Solution 
{
public:
    
    vector<string> ans;
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    class Trie
    {
    public:
        Trie *links[26];
        bool isEnd = false;
    };
    
    void insert(Trie *root, string &word)
    {
        Trie *curr = root;
        
        for(int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if(!curr -> links[idx])
                curr -> links[idx] = new Trie();
            
            curr = curr -> links[idx];
        }
        
        curr -> isEnd = true;
        return;
    }
    
    bool isValid(vector<vector<char>> &board, int x, int y)
    {
        int row = board.size();
        int col = board[0].size();
        
        if(x < 0 || x >= row || y < 0 || y >= col || board[x][y] == '*')
            return false;
        
        return true;
    }
    
    void search(vector<vector<char>> &board, int cx, int cy, Trie *root, string &str)
    {
        if(board[cx][cy] == '*')
            return;
        
        int idx = board[cx][cy] - 'a';
        
        if(!root -> links[idx])
            return;
        
        str.push_back(board[cx][cy]);
        
        char ch = board[cx][cy];
        board[cx][cy] = '*';
        
        if(root -> links[idx] -> isEnd)
        {
            ans.push_back(str);
            root -> links[idx] -> isEnd = false;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int x = cx + dx[i];
            int y = cy + dy[i];
            
            if(isValid(board, x, y))
                search(board, x, y, root -> links[idx], str);   // Recursive call
        }
        
        // Backtracking
        board[cx][cy] = ch;
        str.pop_back();
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        Trie *root = new Trie();
        
        for(auto &word: words)
            insert(root, word);
        
        int row = board.size();
        int col = board[0].size();
        
        string str = "";
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                search(board, i, j, root, str);
        
        return ans;
    }
};