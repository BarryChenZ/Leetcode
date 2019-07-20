class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=(m>0)? board[0].size():0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
            if (dfs(board, word, m, n, i, j, 0))
                return true;
            }
        }
        return false;
    }
    int dfs (vector<vector<char>>& board, string word, int m, int n, int i, int j, int c) {
        int ret=0;
        if ((i<0) || (j>=n) || (i>=m) || (j<0) || board[i][j]!=word[c])
            return 0;
        if (c==word.size()-1)
            return 1;
        char x = board[i][j];
        board[i][j]='\0';
        ret = dfs(board, word, m, n, i-1, j, c+1);
        if (!ret) ret = dfs(board, word, m, n, i+1, j, c+1);
        if (!ret) ret = dfs(board, word, m, n, i, j-1, c+1);
        if (!ret) ret = dfs(board, word, m, n, i, j+1, c+1);
        board[i][j] = x;
        return ret;
    }
};
