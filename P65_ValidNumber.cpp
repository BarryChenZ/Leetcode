class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int res;
        int n = grid.size();
        if(n == 0) return res;
        int m = grid[0].size();
        if(m == 0) return res;
        int temp = 0;
        long board[n][m];
        cout << n << m << endl;
        for(int i = 0; i < m; i++){ 
            board[0][i] = temp + grid[0][i];
            temp += grid[0][i];
        }
        temp = 0;
        for(int i = 0; i < n; i++){
            board[i][0] = temp + grid[i][0];
            temp += grid[i][0];
        }
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                board[i][j] = min(board[i-1][j],board[i][j-1]) + grid[i][j];
        return board[n-1][m-1];     
    }
};
