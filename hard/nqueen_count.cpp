class Solution {
public:
    int ans;
    int n;    
public:
    int totalNQueens(int n) {
        this->n = n;
        vector<string> board(n, string(n,'.'));
        dfs(board, 0);
        return ans;
    }
    
    void dfs(vector<string> &board, int r){
        if(r == n){
            ans++;
            return;
        }
        
        for(int c = 0; c < n; c++)
        {
            board[r][c] = 'Q';
            if(valid(board, r, c))
                dfs(board, r + 1);
            board[r][c] = '.';
        }
    }
    
    //is it valid after filling row r? (test row r against [0..r-1])
    bool valid(vector<string> &board, int r, int c)
    {
        for(int i = 0; i < r; i++)
        {
            int offset = r - i;
            //same column or diagonal
            if(board[i][c] == 'Q' or 
                (c - offset >= 0 and board[i][c - offset] == 'Q') or 
                (c + offset < n and board[i][c + offset] == 'Q'))
                return false;
        }
        return true;
    }
    
};
