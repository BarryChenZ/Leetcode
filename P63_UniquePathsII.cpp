class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long board[m][n];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            board[0][i] = 1;
            if(obstacleGrid[0][i] == 1){
                board[0][i] = 0;
                break;
            }
        }
        for(int i = 0; i < m; i++){
            board[i][0] = 1;
            if(obstacleGrid[i][0] == 1){
                board[i][0] = 0;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    board[i][j] = 0;
                }
                else board[i][j] = board[i-1][j] + board[i][j-1];
            }
        }
        return board[m-1][n-1];     
    }
};
